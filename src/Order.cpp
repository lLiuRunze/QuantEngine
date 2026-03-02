#include "Order.h"
std::string Order::getSymbol() const {
    return symbol;
}
int Order::getQuantity() const {
    return quantity;
}
double Order::getPrice() const {
    return price;
}