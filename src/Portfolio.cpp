#include<vector>
#include<string>
#include "Portfolio.h"
#include "Position.h"
#include "Trade.h"
#include "Order.h"

double Portfolio::getCash() const {
    return cash;
}

double Portfolio::getTotalValue(double currentPrice) const {
    double totalValue = cash;
    for (const auto &entry : positions) {
        const Position &pos = entry.second;
        totalValue += pos.getQuantity() * currentPrice;
    }
    return totalValue;
}
std::map<std::string, Position> &Portfolio::getPositions() {
    return positions;
}
const std::vector<Trade> &Portfolio::getTradeHistory() const {
    return tradeHistory;
}

void Portfolio::executeOrder(const Order &order, double price, const std::string &time){
    int quantity = order.getQuantity();
    cash -= quantity * price;
    std::string symbol = order.getSymbol();
    auto [it,inserted] = positions.emplace(symbol, Position(symbol));
    it->second.update(Trade(symbol, quantity, price, time));
    tradeHistory.emplace_back(symbol, quantity, price, time);
}