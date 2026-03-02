#include "Trade.h"
std::string Trade::getSymbol() const {
    return symbol;
}
int Trade::getQuantity() const {
    return quantity;
}   
double Trade::getPrice() const {
    return price;
}
std::string Trade::getTime() const {
    return time;
}