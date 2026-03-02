#include "core/Order.h"

const std::string &Order::getSymbol() const { return symbol; }
int Order::getQuantity() const { return quantity; }
double Order::getPrice() const { return price; }
