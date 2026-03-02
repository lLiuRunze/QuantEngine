#pragma once
#include <vector>
#include <string>
class Order
{
private:
    std::string symbol; // 股票标识，可以固定 "SINGLE"
    int quantity;       // 买卖数量，正数买，负数卖
    double price;

public:
    Order(const std::string &symbol, int quantity, double price)
        : symbol(symbol), quantity(quantity), price(price) {}
    std::string getSymbol() const;
    int getQuantity() const;
    double getPrice() const;
};