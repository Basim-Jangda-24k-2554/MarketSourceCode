#ifndef USER_H
#define USER_H

#include <string>
#include <map>
#include "StockMarket.h"
using namespace std;

class User {
private:
    string name;
    double assetValue;
    map<string, int> ownedStocks;
    StockMarket& stockMarket;

public:
    User(const string& username, StockMarket& market);
    void buyStock(Stock* stock, int quantity);
    void sellStock(Stock* stock, int quantity);
    void displayPortfolio() const;
    double calculateAssetValue() const;
    void savePortfolio() const;
    void loadPortfolio();
    double getAssetValue() const;
    string getuserName() const;
    const std::map<std::string, int>& getOwnedStocks() const;

};

#endif // USER_H
