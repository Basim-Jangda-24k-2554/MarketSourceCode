#include "StockMarket.h"
#include <cstdlib>

StockMarket::StockMarket() {
}

std::vector<std::string> StockMarket::getStockNames() const {
    std::vector<std::string> stockNames;

    // Iterate through the map and add the stock names to the vector
    for (const auto& stockPair : stocks) {
        stockNames.push_back(stockPair.first);
    }

    return stockNames;
}
StockMarket::~StockMarket() {
    for (auto& pair : stocks)
        delete pair.second;
}

void StockMarket::addStock(Stock* stock) {
    stocks[stock->getName()] = stock;
}

Stock* StockMarket::getStock(const string& stockName) {
    return stocks.count(stockName) ? stocks[stockName] : nullptr;
}

void StockMarket::simulateMonth() {
    for (auto& pair : stocks) {
        double change = (rand() % 11 - 5); // -5% to +5%
        if (change >= 0)
            pair.second->raisePrice(change);
        else
            pair.second->decreasePrice(-change);
    }
}
