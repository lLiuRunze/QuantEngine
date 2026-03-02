#include "core/Position.h"
#include "core/Trade.h" // 前向声明不够，实现时需要完整定义

const std::string &Position::getSymbol() const { return symbol; }
int Position::getQuantity() const { return quantity; }
double Position::getAvgPrice() const { return avgprice; }

void Position::update(const Trade &trade)
{
    int oldQuantity = quantity;
    if (oldQuantity + trade.getQuantity() == 0)
    {
        quantity = 0;
        avgprice = 0.0;
        return;
    }
    quantity = oldQuantity + trade.getQuantity();
    avgprice = (avgprice * oldQuantity + trade.getPrice() * trade.getQuantity()) / quantity;
}
