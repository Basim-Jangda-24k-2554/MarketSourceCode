#ifndef TECHNOLOGYSTOCK_H
#define TECHNOLOGYSTOCK_H

#include "Stock.h"

class TechnologyStock : public Stock {
public:
    TechnologyStock(const string& name, double price);
    std::string getType() const override {return "Technology";}
    double getTaxRate() const {return taxRate;}
    double calculateBuyPrice(int quantity) const override;
    double calculateSellPrice(int quantity) const override;
};

#endif
