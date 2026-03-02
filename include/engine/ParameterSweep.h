#pragma once

#include <vector>
#include <future>
#include "engine/BacktestConfig.h"
struct ParameterResult
{
    int window;
    double finalValue;
};
class ParameterSweep
{
public:
    ParameterSweep(const std::vector<double> &prices,
                   const BacktestConfig &config)
        : prices_(prices), config_(config) {}

    double runSingle(int window);

    std::vector<ParameterResult> runBatch(
        const std::vector<int> &windows,const int numThreads);

private:
    const std::vector<double> &prices_;
    BacktestConfig config_;
};