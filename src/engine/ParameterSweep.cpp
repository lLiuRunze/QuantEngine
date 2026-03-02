#include "engine/ParameterSweep.h"
#include "strategy/MovingAverage.h"
#include "engine/BackEngine.h"
#include <iostream>
double ParameterSweep::runSingle(int window)
{
    auto strategy = std::make_unique<MovingAverage>(window);

    Portfolio portfolio(config_.initCash,
                        config_.initPositions);

    BackEngine engine(prices_,
                      std::move(strategy),
                      std::move(portfolio));

    engine.run();

    return engine.getFinalValue();
}

std::vector<ParameterResult> ParameterSweep::runBatch(const std::vector<int> &windows,const int numThreads){

    unsigned int maxThreads =
        std::thread::hardware_concurrency();
    if (numThreads > 0 && numThreads < maxThreads)
    {
        maxThreads = numThreads;
    }else if (numThreads <= 0)
    {
        maxThreads = 1; 
    }
    std::cout << "Using " << maxThreads << " threads" << std::endl;

    std::vector<ParameterResult> results;
    for (size_t i = 0; i < windows.size(); i += maxThreads)
    {
        std::vector<std::future<ParameterResult>> futures;
        for (size_t j = i;
             j < i + maxThreads && j < windows.size();
             ++j)
        {
            futures.push_back(
                std::async(std::launch::async,
                           [this, w = windows[j]]()
                           {
                               double val = runSingle(w);
                               return ParameterResult{w, val};
                           }));
        }
        for (auto &f : futures)
        {
            results.push_back(f.get());
        }
    }
    // std::vector<std::future<double>> futures;
    // for (int window: windows){
    //     futures.push_back(std::async(std::launch::async, &ParameterSweep::runSingle, this, window));
    // }

    // for (size_t i = 0; i < windows.size(); ++i) {
    //     results.push_back({windows[i], futures[i].get()});
    // }
    return results;
}