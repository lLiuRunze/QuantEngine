#pragma once
#include<vector>
#include<string>
using namespace std;
class DataGenerator
{
public:
    vector<double> generateData(int n,double mu,double sigma,double s0,double dt);
    void saveToCSV(const vector<double>& data, const string& filename);
};