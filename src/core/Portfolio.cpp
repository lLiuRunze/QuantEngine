#include "core/Portfolio.h"
#include "core/Order.h" // 前向声明不够，实现时需要完整定义

double Portfolio::getCash() const { return cash; }

double Portfolio::getTotalValue(double currentPrice) const
{
    double totalValue = cash;
    for (const auto &entry : positions)
        totalValue += entry.second.getQuantity() * currentPrice;
    return totalValue;
}

const std::map<std::string, Position> &Portfolio::getPositions() const { return positions; }
std::map<std::string, Position> &Portfolio::getPositions() { return positions; }

const std::vector<Trade> &Portfolio::getTradeHistory() const { return tradeHistory; }

void Portfolio::executeOrder(const Order &order, double price, const std::string &time)
{
    const int quantity = order.getQuantity();
    cash -= quantity * price;
    const std::string &symbol = order.getSymbol();
    auto [it, inserted] = positions.emplace(symbol, Position(symbol));
    it->second.update(Trade(symbol, quantity, price, time));
    tradeHistory.emplace_back(symbol, quantity, price, time);
}
