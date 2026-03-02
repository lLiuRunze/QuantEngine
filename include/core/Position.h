#pragma once
#include <string>

class Trade; // 前向声明：只用作参数引用，无需完整定义

class Position
{
private:
    std::string symbol;
    int quantity;
    double avgprice;

public:
    Position(const std::string &symbol) : symbol(symbol), quantity(0), avgprice(0.0) {}
    const std::string &getSymbol() const; // 返回引用，避免拷贝
    int getQuantity() const;
    double getAvgPrice() const;
    void update(const Trade &trade);
};
