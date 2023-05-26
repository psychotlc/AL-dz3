#include "graph.hpp"

#include <iostream>
#include <algorithm>
#include <math.h>

graph::graph() :size(0), Matrix(0)  {}

graph::graph(int N) 
    :size(N), 
    Matrix(N, std::vector<int>(N, 0))  {}

graph::graph(graph& other) 
    :size(other.size), 
    Matrix(size, std::vector<int> (size, 0) ) 
{
    for(int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) Matrix[i][j] = other.Matrix[i][j];
}

graph::graph(std::vector <int> other): graph(sqrt(other.size())) {
    if (!(this->size * this->size == other.size())) throw error("Incorrect input: it's not a matrix\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            Matrix[i][j] = other[size * i + j];
        }
    }
};

void graph::setElement(int i, int j, int Element){
    Matrix[i][j] = Element;
};



int graph::getN() const {
    return this->size;
};



void graph::print(){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) std::cout<<Matrix[i][j] << " ";
        std::cout << std::endl;
    }
};


std::vector <std::vector <int> > graph::AllWays(int begin, int end){
    ways.clear();
    std::vector <int> way;
    AllWaysRecursive(begin, end, way);
    return ways;
};

void graph::AllWaysRecursive(int begin, int end, std::vector<int>& way){
    way.push_back(begin);
    if (begin == end){
        ways.push_back(way);
        return;
    }

    for (int i = 0; i < size; i++){
        if ( Matrix[begin][i] == 1){
            if (! std::count(way.begin(), way.end(), i)){
                AllWaysRecursive(i, end, way);
                way.pop_back();
            }
        }
    }
};