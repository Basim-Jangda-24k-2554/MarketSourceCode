#ifndef TEXTILESTOCK_H
#define TEXTILESTOCK_H

#include "Stock.h"
using namespace std;

class TextileStock : public Stock {
public:
    TextileStock(const string& name, double price);
    std::string getType() const override {return "Textile";}
    double calculateBuyPrice(int quantity) const override;
    double calculateSellPrice(int quantity) const override;
};

#endif // TEXTILESTOCK_H
