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

void graph::setElement(int i, int j, int Element){
    Matrix[i][j] = Element;
};

std::vector <int> graph::ShortestWay(int begin, int end){
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
            if (Matrix[i][j] != 0){
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
    std::cout << n;
    return {-1};
    
};

int graph::getN() const {
    return this->n;
};

graph::graph(std::vector <int> other): graph(pow(other.size(), 0.5)) {
        
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            Matrix[i][j] = other[n * i + j];
        }
    }
};

void graph::print(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) std::cout<<Matrix[i][j] << " ";
        std::cout << std::endl;
    }
};