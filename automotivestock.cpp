#include "automotivestock.h"

AutomotiveStock::AutomotiveStock(const string& name, double price)
    : Stock(name, price, 0.06) {}

double AutomotiveStock::calculateBuyPrice(int quantity) const {
    return quantity * currentPrice * (1 + taxRate);
}

double AutomotiveStock::calculateSellPrice(int quantity) const {
    return quantity * currentPrice;
}
