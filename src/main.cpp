#include "data/DataGenerator.h"
#include "strategy/MovingAverage.h"
#include "engine/BackEngine.h"
#include "core/Portfolio.h"
#include "core/Position.h"
#include "analytics/PerformanceAnalyzer.h"
#include "engine/ParameterSweep.h"
#include "engine/BacktestConfig.h"
#include <iostream>
#include <memory>
#include <chrono>

int main()
{

    DataGenerator gen;
    std::vector<double> data = gen.generateData(1000000, -0.05, 0.2, 5, 0.01);

    BacktestConfig config;
    config.initCash = 100000.0;
    config.initPositions = {{"SINGLE", Position("SINGLE")}};

    ParameterSweep sweep(data, config);
    std::vector<int> windows;
    for (int i = 5; i <= 500; i += 5)
    {
        windows.push_back(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    auto results = sweep.runBatch(windows,5);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration<double>(end - start);
    std::cout << "Multi-threaded processing time: " << elapsed.count() << " seconds" << std::endl;

    // start = std::chrono::high_resolution_clock::now();
    // for (int window : windows)
    // {
    //     sweep.runSingle(window);
    // }
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration<double>(end - start);
    // std::cout << "Single-threaded processing time: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}