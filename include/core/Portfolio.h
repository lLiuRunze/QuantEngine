#pragma once
#include <vector>
#include <string>
#include <map>
#include "core/Position.h"
#include "core/Trade.h"

class Order; // 前向声明：只用作 const 引用参数，无需完整定义

class Portfolio
{
private:
    double cash;
    std::map<std::string, Position> positions;
    std::vector<Trade> tradeHistory;

public:
    Portfolio(double initialCash, const std::map<std::string, Position> &init_positions = {})
        : cash(initialCash), positions(init_positions) {}
    double getCash() const;
    void executeOrder(const Order &order, double price, const std::string &time);
    double getTotalValue(double currentPrice) const;
    const std::map<std::string, Position> &getPositions() const; // const 重载，只读访问
    std::map<std::string, Position> &getPositions();
    const std::vector<Trade> &getTradeHistory() const;
};
