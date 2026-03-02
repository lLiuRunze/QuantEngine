#include <fstream>
#include <sstream>
#include <iostream>

#include "CSVLoader.h"

std::vector<double> CSVLoader::load(const std::string &filename){
    std::vector<double> data;
    std::ifstream file(filename);
    if (file.is_open()){
        std::string line;
        std::getline(file, line);
        while(std::getline(file,line)){
            std::stringstream ss(line);
            std::string index_str, price_str;
            if (std::getline(ss, index_str, ',') && std::getline(ss, price_str)){
                double price = double(std::stod(price_str));
                data.push_back(price);
            }
        }    
    }
    else{
        std::cout << "Unable to open file: " << filename << std::endl;
    }
    return data;    
}
