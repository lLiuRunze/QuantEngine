#pragma once
#include <vector>
#include "Strategy.h"
class MovingAverage : public Strategy
{
private:
    int window;
    std::vector<double> prices;
    int signal;
    double lastPrice;
    double lastAvg;
public:
    MovingAverage(int window) : window(window), signal(0) {}
    void onBar(double price) override;
    int getSignal() const override;
};