#ifndef STOCK_H
#define STOCK_H
#include<vector>
#include <string>
using namespace std;

struct StockData {
    string month;
    double open;
    double high;
    double low;
    double close;
};

class Stock {
protected:

    string name;
    double currentPrice;
    double taxRate;

public:
    vector<StockData> history;
    Stock(const string& name, double price, double tax);
    const std::vector<StockData>& getHistory() const {
        return history;
    }
    virtual double getTaxRate() const {return taxRate;}
    virtual string getType() const = 0;
    virtual double calculateBuyPrice(int quantity) const = 0;
    virtual double calculateSellPrice(int quantity) const = 0;

    virtual void raisePrice(double percent);
    virtual void decreasePrice(double percent);

    void loadStockData(const string& folder);

    double getCurrentPrice() const;
    string getName() const;
};

#endif // STOCK_H
