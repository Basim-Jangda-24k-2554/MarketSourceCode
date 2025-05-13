#include "TextileStock.h"

TextileStock::TextileStock(const string& name, double price)
    : Stock(name, price, 0.05) {}

double TextileStock::calculateBuyPrice(int quantity) const {
    return quantity * currentPrice * (1 + taxRate);
}

double TextileStock::calculateSellPrice(int quantity) const {
    return quantity * currentPrice;
}
