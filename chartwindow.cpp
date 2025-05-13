#include "ChartWindow.h"
#include <QtCharts/QCandlestickSeries>
#include <QtCharts/QCandlestickSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>


ChartWindow::ChartWindow(Stock* stock, QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle(QString::fromStdString(stock->getName()) + " - Candlestick Chart");
    resize(800, 600);
    setupCandlestickChart(stock);
}

ChartWindow::~ChartWindow() {}

void ChartWindow::setupCandlestickChart(Stock* stock) {
    auto* series = new QCandlestickSeries();
    series->setName("Price History");
    series->setIncreasingColor(Qt::green);
    series->setDecreasingColor(Qt::red);

    const auto& history = stock->getHistory();
    // Start date based on the number of entries in the stock's history
    QDateTime startDate = QDateTime::currentDateTime().addMonths(-history.size() + 1);

    for (int i = 0; i < history.size(); ++i) {
        const StockData& data = history[i];
        QDateTime date = startDate.addMonths(i);

        QCandlestickSet* set = new QCandlestickSet(data.open, data.high, data.low, data.close);
        set->setTimestamp(date.toMSecsSinceEpoch());
        series->append(set);
    }

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Candlestick Chart for " + QString::fromStdString(stock->getName()));
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setTitleText("Time (simulated)");
    chart->axes(Qt::Vertical).first()->setTitleText("Price");

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(chartView);
}


