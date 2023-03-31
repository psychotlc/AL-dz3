#include "graph.hpp"

#include <iostream>
#include <algorithm>
#include <math.h>



graph::graph() :n(0), Matrix(0)  {}

graph::graph(int N) 
    :n(N), 
    Matrix(N, std::vector<int>(N, 0))  {}

graph::graph(graph& other) 
    :n(other.n), 
    Matrix(n, std::vector<int> (n, 0) ) 
{
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) Matrix[i][j] = other.Matrix[i][j];
}

graph::graph(std::vector <int> other): graph(sqrt(other.size())) {
    if (!(this->n * this->n == other.size())) throw error("Incorrect input: it's not a matrix\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            Matrix[i][j] = other[n * i + j];
        }
    }
};

void graph::setElement(int i, int j, int Element){
    Matrix[i][j] = Element;
};

std::vector <int> graph::ShortestWay(int begin, int end){
    if (this->n <= end || end < 0) {
        throw error("Incorrect end point");
        
    }

    if (begin >= this->n || begin < 0){
        throw error("Incorrect begin point");
        
    }

    std::vector <int> allVisitedPoint = {begin};
    std::vector <Point> points;
    Point tmp(begin);
    tmp.way.push_back(begin);
    points.push_back(tmp);
    int size = points.size();

    for (int k = 0; k < size; k++){
        for (int i = 0; i < n; i++){
            auto j = points[k].way[points[k].way.size() - 1];
            if (Matrix[j][i] != 0){
                if (std::count(allVisitedPoint.begin(), allVisitedPoint.end(), i) == 0){
                    
                    tmp = points[k];
                    tmp.way.push_back(i);
                    points.push_back(tmp);
                    size++;
                    if (i == end) return tmp.way;
                    allVisitedPoint.push_back(i);
                }
            }
            else if (Matrix[i][j] != 0){
                if (std::count(allVisitedPoint.begin(), allVisitedPoint.end(), j) == 0){
                    
                    tmp = points[k];
                    tmp.way.push_back(j);
                    points.push_back(tmp);
                    size++;
                    if (j == end) return tmp.way;
                    allVisitedPoint.push_back(i);
                }
            }
        }
    }
    
    error e("There is no way");
    throw e;
    
};

int graph::getN() const {
    return this->n;
};



void graph::print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) std::cout<<Matrix[i][j] << " ";
        std::cout << std::endl;
    }
};