#include "Stock.h"
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QFile>
#include <QString>


Stock::Stock(const string& name, double price, double tax)
    : name(name), currentPrice(price), taxRate(tax) {}

void Stock::raisePrice(double percent) {
    currentPrice += currentPrice * (percent / 100);
}

void Stock::decreasePrice(double percent) {
    currentPrice -= currentPrice * (percent / 100);
}

void Stock::loadStockData(const string& folder) {
    string filename = folder + "/stock_" + name + ".csv";
    QFile file(QString::fromStdString(filename));
    if (!file.exists()) return;

    ifstream inFile(filename);
    if (!inFile.is_open()) return;

    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        StockData data;

        getline(ss, token, ',');
        data.month = token;

        getline(ss, token, ',');
        istringstream(token) >> data.open;

        getline(ss, token, ',');
        istringstream(token) >> data.high;

        getline(ss, token, ',');
        istringstream(token) >> data.low;

        getline(ss, token, ',');
        istringstream(token) >> data.close;

        history.push_back(data);
    }
}





double Stock::getCurrentPrice() const {
    return currentPrice;
}

string Stock::getName() const {
    return name;
}
