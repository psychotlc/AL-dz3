#ifndef GRAPH
#define GRAPH

#include <vector>
#include <string>


class graph{
    
public:

    graph();
    graph(int N) ;
    graph(graph& other) ;
    graph(std::vector <int> other);
    void setElement(int i, int j, int Element);
    std::vector <std::vector <int> > AllWays(int begin, int end);
    void print();
    int getN() const;

private:

    std::vector <std::vector <int> > Matrix;
    int size;
    std::vector<std::vector <int> > ways;
    void AllWaysRecursive(int begin, int end, std::vector<int>& way);
    
};

struct error{
    std::string text;
    error(std::string text) :text(text){};
    std::string what() const{ return text;};
};

#endif