#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QCandlestickSet>
#include <QDateTime>
#include "Stock.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChartWindow; }
QT_END_NAMESPACE

class ChartWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ChartWindow(Stock* stock, QWidget* parent = nullptr);
    ~ChartWindow();

private:
    QChartView* chartView;
    void setupCandlestickChart(Stock* stock);
};

#endif // CHARTWINDOW_H
