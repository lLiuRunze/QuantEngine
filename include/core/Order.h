#pragma once
#include <string>

class Order
{
private:
    std::string symbol;
    int quantity;
    double price;

public:
    Order(const std::string &symbol, int quantity, double price)
        : symbol(symbol), quantity(quantity), price(price) {}
    const std::string &getSymbol() const; // 返回引用，避免拷贝
    int getQuantity() const;
    double getPrice() const;
};
