#include "MovingAverage.h"
#include <iostream>
void MovingAverage::onBar(double price)
{
    prices.push_back(price);
    if (prices.size() < window)
    {
        signal = 0;
        return;
    }
    if ((int)prices.size() > window)
    {
        prices.erase(prices.begin());
    }
    double sum = 0.0;
    for (double p : prices)
        sum += p;
    double avg = prices.empty() ? 0.0 : sum / prices.size();

    if (price > avg && lastPrice <= lastAvg)
    {
        signal = 1;
    }

    else if (price < avg && lastPrice >= lastAvg)
    {
        signal = -1;
    }

    else
    {
        signal = 0;
    }
    lastPrice = price;
    lastAvg = avg;
}

int MovingAverage::getSignal() const
{
    return signal;
}
