#include "TechnologyStock.h"

using namespace std;

TechnologyStock::TechnologyStock(const string& name, double price)
    : Stock(name, price, 0.07) {}

double TechnologyStock::calculateBuyPrice(int quantity) const {
    return quantity * currentPrice * (1 + taxRate);
}

double TechnologyStock::calculateSellPrice(int quantity) const {
    return quantity * currentPrice;
}
