#pragma once
#include <vector>
#include "Strategy.h"
#include "Portfolio.h"
#include "Position.h"
class BackEngine{
    private:
        const std::vector<double> &data;
        Strategy* strategy;
        Portfolio portfolio;
        std::vector<double> equityCurve;

    public:
        BackEngine(const std::vector<double> &prices, Strategy *strategy, Portfolio Portfolio) : data(prices), strategy(strategy), portfolio(Portfolio) {};
        void run();
        double getFinalValue() const;
        const std::vector<double> &getEquityCurve() const;
};
