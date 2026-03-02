#pragma once
#include <vector>
#include <string>
#include <map>
#include "Position.h"
#include "Trade.h"
#include "Order.h"
class Portfolio{
    private:
        double cash;
        std::map<std::string, Position> positions; // key: symbol, value: 
        std::vector<Trade> tradeHistory;
    public:
        Portfolio(double initialCash, const std::map<std::string, Position> &init_positions = std::map<std::string, Position>()) : cash(initialCash), positions(init_positions) {}
        double getCash() const;
        void executeOrder(const Order &order, double price, const std::string &time);
        double getTotalValue(double currentPrice) const;
        std::map<std::string, Position>& getPositions();
        const std::vector<Trade>& getTradeHistory() const;
};