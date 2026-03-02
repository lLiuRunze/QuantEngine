#pragma once
#include <string>
#include "Trade.h"
#include "Order.h"  
class Position{
    private:
        std::string symbol; // 股票标识，可以固定 "SINGLE"
        int quantity;       // 持仓数量，正数多头，负数空头
        double avgprice;  
    public:
        Position(const std::string& symbol) : symbol(symbol), quantity(0), avgprice(0.0) {} 
        std::string getSymbol() const;
        int getQuantity() const;
        double getAvgPrice() const;
        void update(const Trade &trade);
};