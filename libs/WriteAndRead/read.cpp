#include "read.hpp"
#include <fstream>
#include <iostream>
#include "graphs.hpp"

void read(std::string file_name){
    std::ifstream file(file_name,std::ios_base::binary);
    graph tmp;

    file.read((char*)&tmp, sizeof(tmp));
    // auto result = tmp.ShortestWay(1, 5);
    // for (auto it = result.begin(); it != result.end(); it++) std::cout << *it << " ";
    // file.close();
};