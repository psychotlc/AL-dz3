#include "read.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include "graphs.hpp"


void read(std::string file_name){
    std::ifstream file(file_name,std::ios_base::binary);
    

    std::string stringtmp = "";
    std::vector <int> intTmp;
    try{
        while (!file.eof()){
            file >> stringtmp;
            intTmp.push_back(std::stoi(stringtmp));
        }
    } catch( std::invalid_argument e){
        std::cout << "InCorrect input" << std::endl;
        return;
        };
    intTmp.pop_back();
    graph tmp(intTmp);
    auto result = tmp.ShortestWay(0, 3);
    for (auto it = result.begin(); it != result.end(); it++) std::cout << *it;
    file.close();
};