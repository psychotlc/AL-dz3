#include <iostream>
#include "graphs.hpp"
#include "Read.hpp"

using namespace std;

int main(int argc, char* argv[]){
    if (string(argv[1]) == "read") read(argv[2]);
    return 0;
}