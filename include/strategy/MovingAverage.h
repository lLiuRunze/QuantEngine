#pragma once
#include <vector>
#include "strategy/Strategy.h"

class MovingAverage : public Strategy
{
private:
    int window;
    std::vector<double> prices;
    int signal;
    double lastPrice; // 已正确初始化，原代码未初始化（潜在 bug）
    double lastAvg;

public:
    MovingAverage(int window) : window(window), signal(0), lastPrice(0.0), lastAvg(0.0) {}
    void onBar(double price) override;
    int getSignal() const override;
};
