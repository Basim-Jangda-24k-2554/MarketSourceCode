#include "PharmaceuticalStock.h"

using namespace std;

PharmaceuticalStock::PharmaceuticalStock(const string& name, double price)
    : Stock(name, price, 0.04) {}

double PharmaceuticalStock::calculateBuyPrice(int quantity) const {
    return quantity * currentPrice * (1 + taxRate);
}

double PharmaceuticalStock::calculateSellPrice(int quantity) const {
    return quantity * currentPrice;
}
