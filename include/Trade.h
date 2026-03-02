#pragma once
#include <vector>
#include <string>

class Trade {
    private:
        std::string symbol; // 股票标识，可以固定 "SINGLE"
        int quantity;       // 买卖数量，正数买，负数卖
        double price;
        std::string time;
    public:
        Trade(const std::string &symbol, int quantity, double price, const std::string &time)
            : symbol(symbol), quantity(quantity), price(price), time(time) {}
        std::string getSymbol() const;
        int getQuantity() const;
        double getPrice() const;
        std::string getTime() const;
};