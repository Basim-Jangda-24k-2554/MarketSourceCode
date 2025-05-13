#ifndef AUTOMOTIVESTOCK_H
#define AUTOMOTIVESTOCK_H

#include "Stock.h"
using namespace std;

class AutomotiveStock : public Stock {
public:
    AutomotiveStock(const string& name, double price);
    virtual string getType() const override{return "AutoMotive";}
    double calculateBuyPrice(int quantity) const override;
    double calculateSellPrice(int quantity) const override;
};

#endif
