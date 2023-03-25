#include <iostream>
#include "graphs.hpp"
#include "WriteAndRead.hpp"

using namespace std;

int main(int argc, char* argv[]){
    if (string(argv[1]) == "write") write(argv[2]);
    else if (string(argv[1]) == "read") read(argv[2]);
    return 0;
}