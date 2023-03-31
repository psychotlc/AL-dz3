#ifndef GRAPH
#define GRAPH

#include <vector>
#include <string>

class Point{
public:
    Point(int n) {
        this->position = n;
    }
    int position;
    std::vector<int> way;
};

class graph{
    
public:
    graph();
    graph(int N) ;
    graph(graph& other) ;
    graph(std::vector <int> other);
    void setElement(int i, int j, int Element);
    virtual std::vector <int> ShortestWay(int begin, int end);
    void print();
    int getN() const;
protected:
    std::vector <std::vector <int> > Matrix;
    int n;
    
};

struct error{
    std::string text;
    error(std::string text) :text(text){};
    std::string what() const{ return text;};
};

#endif