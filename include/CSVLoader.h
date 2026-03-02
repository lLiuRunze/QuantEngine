#pragma once
#include <vector>
#include <string>

class CSVLoader
{
public:
    static std::vector<double> load(const std::string &filename);
};