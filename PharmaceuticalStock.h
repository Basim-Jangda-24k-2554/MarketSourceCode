#ifndef PHARMACEUTICALSTOCK_H
#define PHARMACEUTICALSTOCK_H

#include "Stock.h"

class PharmaceuticalStock : public Stock {
public:
    PharmaceuticalStock(const string& name, double price);
    std::string getType() const override {return "Pharma";}
    double calculateBuyPrice(int quantity) const override;
    double calculateSellPrice(int quantity) const override;
};

#endif
