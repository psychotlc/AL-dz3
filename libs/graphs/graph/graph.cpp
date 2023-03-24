#include "graph.hpp"

#include <iostream>

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