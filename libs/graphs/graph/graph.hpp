#ifndef GRAPH
#define GRAPH

#include <vector>

class graph{
    
public:
    graph();
    graph(int N);
    graph(graph& other);
    graph(std::vector <int> other);
    void setElement(int i, int j, int Element);
    std::vector <int> ShortestWay(int begin, int end);
    void print();
    int getN() const;
private:
    std::vector <std::vector <int> > Matrix;
    int n;
    
};

#endif