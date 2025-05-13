#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AutomotiveStock.h"
#include "PharmaceuticalStock.h"
#include "TechnologyStock.h"
#include "TextileStock.h"
#include "User.h"
#include "ChartWindow.h"
#include <sstream>
#include <iostream>
#include <QMessageBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->stackedWidget->setCurrentIndex(0);
    // Add all stocks to the stock market
    stockMarket.addStock(new AutomotiveStock("Honda", 250.0));
    stockMarket.addStock(new AutomotiveStock("Hyundai", 200.0));
    stockMarket.addStock(new AutomotiveStock("Suzuki", 200.0));
    stockMarket.addStock(new AutomotiveStock("Toyota", 150.0));

    stockMarket.addStock(new PharmaceuticalStock("AGP", 140.0));
    stockMarket.addStock(new PharmaceuticalStock("Ferozesons", 500.0));
    stockMarket.addStock(new PharmaceuticalStock("GSK", 100.0));
    stockMarket.addStock(new PharmaceuticalStock("Searle", 300.0));

    stockMarket.addStock(new TechnologyStock("Netsol", 325.0));
    stockMarket.addStock(new TechnologyStock("SystemsLtd", 142.0));
    stockMarket.addStock(new TechnologyStock("Techlogix", 300.0));
    stockMarket.addStock(new TechnologyStock("TRG", 101.0));

    stockMarket.addStock(new TextileStock("AlKaram", 100.0));
    stockMarket.addStock(new TextileStock("GulAhmed", 120.0));
    stockMarket.addStock(new TextileStock("Nishat", 150.0));
    stockMarket.addStock(new TextileStock("Sapphire", 130.0));

    // Load stock data from the appropriate folders
    stockMarket.getStock("Honda")->loadStockData("Data/Automotive");
    stockMarket.getStock("Hyundai")->loadStockData("Data/Automotive");
    stockMarket.getStock("Suzuki")->loadStockData("Data/Automotive");
    stockMarket.getStock("Toyota")->loadStockData("Data/Automotive");

    stockMarket.getStock("AGP")->loadStockData("Data/Pharmaceutical");
    stockMarket.getStock("Ferozesons")->loadStockData("Data/Pharmaceutical");
    stockMarket.getStock("GSK")->loadStockData("Data/Pharmaceutical");
    stockMarket.getStock("Searle")->loadStockData("Data/Pharmaceutical");

    stockMarket.getStock("Netsol")->loadStockData("Data/Technology");
    stockMarket.getStock("SystemsLtd")->loadStockData("Data/Technology");
    stockMarket.getStock("Techlogix")->loadStockData("Data/Technology");
    stockMarket.getStock("TRG")->loadStockData("Data/Technology");

    stockMarket.getStock("AlKaram")->loadStockData("Data/Textile");
    stockMarket.getStock("GulAhmed")->loadStockData("Data/Textile");
    stockMarket.getStock("Nishat")->loadStockData("Data/Textile");
    stockMarket.getStock("Sapphire")->loadStockData("Data/Textile");

    // Initialize user
    user = new User("Ali", stockMarket);
    updatePortfolioUI();
    // Populate the stock table on the Dashboard page
 populateStockTable();

    // button click signals to the corresponding slots
 connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onSimulateMonthClicked);
    connect(ui->buttonPortfolio, &QPushButton::clicked, this, &MainWindow::showPortfolioPage);
    connect(ui->buttonTrade, &QPushButton::clicked, this, &MainWindow::showTradePage);
     connect(ui->buttonDashboard, &QPushButton::clicked, this, &MainWindow::showDashboardPage);
  connect(ui->tableWidgetStocks, &QTableWidget::cellClicked, this, &MainWindow::onStockRowClicked);
     connect(ui->buyButton, &QPushButton::clicked, this, &MainWindow::onBuyButtonClicked);
     connect(ui->sellButton, &QPushButton::clicked, this, &MainWindow::onSellButtonClicked);
     connect(ui->buttonDashboard_2, &QPushButton::clicked, this, &MainWindow::showDashboardPage);
      connect(ui->buttonDashboard_3, &QPushButton::clicked, this, &MainWindow::showDashboardPage);
      connect(ui->buttonInfo, &QPushButton::clicked, this, &MainWindow::showInfoPage);


}

void MainWindow::onStockRowClicked(int row, int) {
    QTableWidgetItem* item = ui->tableWidgetStocks->item(row, 0);  // Stock name is in column 0
    if (!item) return;

    QString stockName = item->text();
    Stock* stock = stockMarket.getStock(stockName.toStdString());

    if (stock) {
        selectedStock = stock;
        ui->labelSelectedStock->setText("Selected: " + QString::fromStdString(stock->getName()));

        // 🔹 Show chart window
        ChartWindow* chartWin = new ChartWindow(stock, this);
        chartWin->setAttribute(Qt::WA_DeleteOnClose);
        chartWin->show();
        ui->stackedWidget->setCurrentIndex(3);
    }
}
void MainWindow::onSimulateMonthClicked() {
    stockMarket.simulateMonth();  // Simulate the month
    populateStockTable();         // Refresh the stock table to reflect updated prices
     updatePortfolioUI();
    QMessageBox::information(this, "Simulation", "One month has been simulated successfully.");
}




MainWindow::~MainWindow()
{
    delete user;
    delete ui;
}

void MainWindow::onBuyButtonClicked() {
    if (!selectedStock) return;  // make sure a stock is selected

    int quantity = ui->spinBoxQuantity->value();
    double cost = selectedStock->calculateBuyPrice(quantity);

    user->buyStock(selectedStock, quantity);

    QMessageBox::information(this, "Buy Successful",QString("Bought %1 shares of %2.").arg(quantity).arg(QString::fromStdString(selectedStock->getName())));

    updatePortfolioUI();
}


void MainWindow::onSellButtonClicked() {
    if (!selectedStock) return;

    int quantity = ui->spinBoxQuantity->value();
    const std::string& stockName = selectedStock->getName();

    if (user->getOwnedStocks().count(stockName) == 0 || user->getOwnedStocks().at(stockName) < quantity) {
        QMessageBox::warning(this, "Sell Failed", "Not enough shares to sell!");
        return;
    }

    double income = selectedStock->calculateSellPrice(quantity);
    user->sellStock(selectedStock, quantity);

    QMessageBox::information(this, "Sell Successful",QString("Sold %1 shares of %2.").arg(quantity).arg(QString::fromStdString(stockName)));

    updatePortfolioUI();  // refresh portfolio after selling
}



void MainWindow::on_viewPortfolioButton_clicked()
{
    user->displayPortfolio();
}

void MainWindow::on_simulateMonthButton_clicked()
{
    stockMarket.simulateMonth();
    QMessageBox::information(this, "Simulation", "Month simulated and stock prices and Porfolio updated.");
}

void MainWindow::populateStockTable() {
    ui->tableWidgetStocks->clearContents();
    ui->tableWidgetStocks->setRowCount(0);

    for (const auto& stockName : stockMarket.getStockNames()) {
        Stock* stock = stockMarket.getStock(stockName);

        if (stock) {
            const auto& history = stock->getHistory();

            if (!history.empty()) {
                double currentPrice = stock->getCurrentPrice();

                double change = 0.0;
                if (history.size() > 1) {
                    const StockData& previousData = history[history.size() - 2];
                    change = currentPrice - previousData.close;
                }

                int row = ui->tableWidgetStocks->rowCount();
                ui->tableWidgetStocks->insertRow(row);

                // Column 0 - Stock Name
                ui->tableWidgetStocks->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(stockName)));

                // Column 1 - Current Price
                ui->tableWidgetStocks->setItem(row, 1, new QTableWidgetItem(QString::number(currentPrice, 'f', 2)));

                // Column 2 - Change with color
                QTableWidgetItem* changeItem = new QTableWidgetItem(QString::number(change, 'f', 2));
                if (change > 0)
                    changeItem->setForeground(Qt::darkGreen);
                else if (change < 0)
                    changeItem->setForeground(Qt::red);
                else
                    changeItem->setForeground(Qt::black); // No change

                ui->tableWidgetStocks->setItem(row, 2, changeItem);
            }
        }
    }
}

void MainWindow::updatePortfolioUI() {
    // Create a string stream to capture the console output
    std::ostringstream oss;
    std::streambuf* old_buf = std::cout.rdbuf(oss.rdbuf());

    // Call the displayPortfolio method
    user->displayPortfolio();
    std::cout.rdbuf(old_buf);

    // Get the output from the string stream and set it to the QTextBrowser
    QString portfolioText = QString::fromStdString(oss.str());
    ui->textBrowserPortfolio->setText(portfolioText);
}


// Slot to switch to the Portfolio Page
void MainWindow::showPortfolioPage()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::showTradePage()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::showInfoPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::showDashboardPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}



