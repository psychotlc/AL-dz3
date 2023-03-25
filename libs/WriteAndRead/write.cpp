#include <iostream>
#include <fstream>
#include "write.hpp"
#include "graphs.hpp"

void write(std::string file_name){
    std::ofstream file(file_name, std::ios_base::binary);
    
    std::cout << "Enter n: ";
    int n;
    std::cin >> n;

    graph tmp(n);
    for (int i = 0; i < n; i++){
        std::cout << "Enter elements for " << i + 1 << " line: " << std:: endl;
        for (int j = 0; j < n; j++) {
            int TempElement;
            std::cin >> TempElement;
            tmp.setElement(i, j, TempElement);
        }
    }
    file.write((char*)&tmp, sizeof(tmp));
    file.close();
}