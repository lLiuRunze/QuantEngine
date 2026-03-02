#include "core/Trade.h"

const std::string &Trade::getSymbol() const { return symbol; }
int Trade::getQuantity() const { return quantity; }
double Trade::getPrice() const { return price; }
const std::string &Trade::getTime() const { return time; }
