#pragma once
#include <string>

class Trade
{
private:
    std::string symbol;
    int quantity;
    double price;
    std::string time;

public:
    Trade(const std::string &symbol, int quantity, double price, const std::string &time)
        : symbol(symbol), quantity(quantity), price(price), time(time) {}
    const std::string &getSymbol() const; // 返回引用，避免拷贝
    int getQuantity() const;
    double getPrice() const;
    const std::string &getTime() const; // 返回引用，避免拷贝
};
