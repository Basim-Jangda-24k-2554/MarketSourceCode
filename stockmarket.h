#ifndef STOCKMARKET_H
#define STOCKMARKET_H

#include <map>
#include <string>
#include "Stock.h"
#include <vector>

using namespace std;

class StockMarket {
private:
    void onStockRowClicked(int row, int column);

public:
    map<string, Stock*> stocks;

    std::vector<std::string> getStockNames() const;
    StockMarket();
    ~StockMarket();

    void addStock(Stock* stock);
    Stock* getStock(const string& stockName);
    void simulateMonth();
};

#endif // STOCKMARKET_H
