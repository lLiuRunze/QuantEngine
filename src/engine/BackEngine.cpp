#include "engine/BackEngine.h"
#include "strategy/Strategy.h" // 前向声明只够声明，调用虚函数时需要完整定义
#include "core/Order.h"
#include <string>

BackEngine::BackEngine(const std::vector<double> &prices,
                       std::unique_ptr<Strategy> strat,
                       Portfolio port)
    : data(prices), strategy(std::move(strat)), portfolio(std::move(port)) {}

void BackEngine::run()
{
    const std::string &symbol = portfolio.getPositions().begin()->first;
    for (int i = 0; i < (int)data.size(); i++)
    {
        const double price = data[i];
        strategy->onBar(price);
        const int signal = strategy->getSignal();
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

double BackEngine::getFinalValue() const { return equityCurve.back(); }
const std::vector<double> &BackEngine::getEquityCurve() const { return equityCurve; }
