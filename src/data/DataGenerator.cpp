#include "data/DataGenerator.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <random>

std::vector<double> DataGenerator::generateData(int n, double mu, double sigma, double s0, double dt)
{
    std::vector<double> prices;
    prices.reserve(n);
    std::mt19937 gen(std::random_device{}());
    std::normal_distribution<double> dist(0.0, 1.0);
    double s = s0;
    prices.push_back(s0);
    for (int i = 1; i < n; i++)
    {
        const double z = dist(gen);
        s = s * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * z);
        prices.push_back(s);
    }
    return prices;
}

void DataGenerator::saveToCSV(const std::vector<double> &data, const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << "index,price\n";
        int index = 0;
        for (const auto &value : data)
            file << index++ << "," << value << "\n";
        file.close();
        std::cout << "Data saved to " << filename << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
