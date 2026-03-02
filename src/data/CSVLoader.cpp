#include "data/CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<double> CSVLoader::load(const std::string &filename)
{
    std::vector<double> data;
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        std::getline(file, line); // 跳过 header 行
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string index_str, price_str;
            if (std::getline(ss, index_str, ',') && std::getline(ss, price_str))
                data.push_back(std::stod(price_str));
        }
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return data;
}
