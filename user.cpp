#include "User.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

User::User(const string& username, StockMarket& market)
    : name(username), assetValue(0.0), stockMarket(market) {
    loadPortfolio();
}

void User::buyStock(Stock* stock, int quantity) {
    double cost = stock->calculateBuyPrice(quantity);
    assetValue -= cost;
    ownedStocks[stock->getName()] += quantity;
    savePortfolio();  // Save portfolio after buying stock
    cout << "Bought " << quantity << " shares of " << stock->getName()
         << " for " << cost << endl;
}

void User::sellStock(Stock* stock, int quantity) {
    if (ownedStocks[stock->getName()] < quantity) {
        cout << "Not enough shares to sell!\n";
        return;
    }
    double income = stock->calculateSellPrice(quantity);
    assetValue += income;
    ownedStocks[stock->getName()] -= quantity;
    savePortfolio();  // Save portfolio after selling stock
    cout << "Sold " << quantity << " shares of " << stock->getName()
         << " for " << income << endl;
}

void User::displayPortfolio() const {
    cout << "\n[Portfolio for " << name << "]\n";
    cout << "Asset Value: " << fixed << setprecision(2) << calculateAssetValue() << endl; // Calculate asset value at runtime
    for (auto& pair : ownedStocks) {
        cout << "Stock: " << pair.first << ", Quantity: " << pair.second << endl;
    }
}

const std::map<std::string, int>& User::getOwnedStocks() const {
    return ownedStocks;
}


double User::calculateAssetValue() const {
    double totalValue = 0.0;
    for (auto& pair : ownedStocks) {
        Stock* stock = stockMarket.getStock(pair.first);
        if (stock) {
            totalValue += stock->getCurrentPrice() * pair.second;
        }
    }
    return totalValue;
}

void User::savePortfolio() const {
    ofstream outFile("portfolio.txt");
    for (const auto& pair : ownedStocks) {
        outFile << pair.first << "," << pair.second << endl;
    }
    outFile.close();
}

void User::loadPortfolio() {
    ifstream inFile("portfolio.txt");
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string stockName;
        int quantity;
        getline(ss, stockName, ',');
        ss >> quantity;
        ownedStocks[stockName] = quantity;
    }
    inFile.close();
}


double User::getAssetValue() const {
    return assetValue;
}

string User::getuserName() const{
    return name;
}
