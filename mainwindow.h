#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StockMarket.h"
#include "User.h"
#include "ChartWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onBuyButtonClicked();
    void onSellButtonClicked();
    void onSimulateMonthClicked();

    void on_viewPortfolioButton_clicked();
    void on_simulateMonthButton_clicked();
     void populateStockTable();
     void onStockRowClicked(int row, int column);

    // Slot to switch to the Pages
    void showPortfolioPage();
    void showTradePage();
    void showDashboardPage();
    void updatePortfolioUI();
    void showInfoPage();

private:
    Stock* selectedStock = nullptr;
    Ui::MainWindow *ui;
    StockMarket stockMarket;  // StockMarket object to manage stocks
    User *user;  // User object to track purchases and portfolio;
};

#endif // MAINWINDOW_H
