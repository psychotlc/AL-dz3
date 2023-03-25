#include "graph.hpp"

#include <iostream>
#include <algorithm>

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
    std::vector < std::vector<int> > visitedPoints;
    visitedPoints.push_back({begin});
    bool AllPointsAreVisited = false;

    while (!AllPointsAreVisited){
        for (auto it = visitedPoints.begin(); it != visitedPoints.end(); it++){
            auto currentPoint = *(--((*it).end()));
            for (int i = 0; i < n; i++) {
                if (this->Matrix[currentPoint][i] != 0) 
                if (std::count(allVisitedPoint.begin(), allVisitedPoint.end(), i) == 0){
                    auto tmp = (*it);
                    tmp.push_back(i);
                    if (i == end) return tmp;
                    visitedPoints.push_back(tmp);
                }
            }
        }
    }
    return {0};
};