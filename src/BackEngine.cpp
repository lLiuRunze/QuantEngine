#include "BackEngine.h"
#include "Order.h"


// void run();
// double getFinalValue() const;
void BackEngine::run()
{
    std::string symbol = portfolio.getPositions().begin()->first;
    for (int i = 0; i < data.size(); i++)
    {
        double price = data[i];
        strategy->onBar(price);
        int signal = strategy->getSignal();
        if (signal == 1)
        {
            Order buyorder(symbol, 100, price);
            portfolio.executeOrder(buyorder, price, std::to_string(i));
        }
        if (signal == -1)
        {
            Order sellorder(symbol, -100, price);
            portfolio.executeOrder(sellorder, price, std::to_string(i));
        }
        equityCurve.push_back(portfolio.getTotalValue(price));
    }
}

double BackEngine::getFinalValue() const
{
    return equityCurve.back();
}

const std::vector<double> &BackEngine::getEquityCurve() const
{
    return equityCurve;
}