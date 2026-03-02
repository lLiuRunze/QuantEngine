#pragma once
#include <vector>
#include <string>

class DataGenerator
{
public:
    // 移除了 using namespace std（头文件中禁止 using namespace）
    std::vector<double> generateData(int n, double mu, double sigma, double s0, double dt);
    void saveToCSV(const std::vector<double> &data, const std::string &filename);
};
