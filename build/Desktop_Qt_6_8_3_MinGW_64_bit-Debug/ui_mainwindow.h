/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableWidget *tableWidgetStocks;
    QPushButton *buttonPortfolio;
    QPushButton *buttonTrade;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *userNameLabel;
    QTextBrowser *textBrowserPortfolio;
    QLabel *label_5;
    QPushButton *buttonDashboard;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *labelSelectedStock;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBoxQuantity;
    QPushButton *buyButton;
    QPushButton *sellButton;
    QPushButton *buttonDashboard_2;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(page);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        tableWidgetStocks = new QTableWidget(page);
        if (tableWidgetStocks->columnCount() < 3)
            tableWidgetStocks->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetStocks->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetStocks->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetStocks->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidgetStocks->setObjectName("tableWidgetStocks");

        verticalLayout_2->addWidget(tableWidgetStocks);

        buttonPortfolio = new QPushButton(page);
        buttonPortfolio->setObjectName("buttonPortfolio");

        verticalLayout_2->addWidget(buttonPortfolio);

        buttonTrade = new QPushButton(page);
        buttonTrade->setObjectName("buttonTrade");

        verticalLayout_2->addWidget(buttonTrade);

        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_3 = new QVBoxLayout(page_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");
        label_2->setWordWrap(true);

        verticalLayout_3->addWidget(label_2);

        userNameLabel = new QLabel(page_3);
        userNameLabel->setObjectName("userNameLabel");
        userNameLabel->setWordWrap(true);

        verticalLayout_3->addWidget(userNameLabel);

        textBrowserPortfolio = new QTextBrowser(page_3);
        textBrowserPortfolio->setObjectName("textBrowserPortfolio");

        verticalLayout_3->addWidget(textBrowserPortfolio);

        label_5 = new QLabel(page_3);
        label_5->setObjectName("label_5");

        verticalLayout_3->addWidget(label_5);

        buttonDashboard = new QPushButton(page_3);
        buttonDashboard->setObjectName("buttonDashboard");

        verticalLayout_3->addWidget(buttonDashboard);

        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        labelSelectedStock = new QLabel(page_2);
        labelSelectedStock->setObjectName("labelSelectedStock");

        verticalLayout_4->addWidget(labelSelectedStock);

        frame_2 = new QFrame(page_2);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName("horizontalLayout");
        spinBoxQuantity = new QSpinBox(frame_2);
        spinBoxQuantity->setObjectName("spinBoxQuantity");
        spinBoxQuantity->setMinimum(1);

        horizontalLayout->addWidget(spinBoxQuantity);

        buyButton = new QPushButton(frame_2);
        buyButton->setObjectName("buyButton");
        buyButton->setCheckable(false);

        horizontalLayout->addWidget(buyButton);

        sellButton = new QPushButton(frame_2);
        sellButton->setObjectName("sellButton");

        horizontalLayout->addWidget(sellButton);


        verticalLayout_4->addWidget(frame_2);

        buttonDashboard_2 = new QPushButton(page_2);
        buttonDashboard_2->setObjectName("buttonDashboard_2");

        verticalLayout_4->addWidget(buttonDashboard_2);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">Dashboard</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetStocks->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Stock Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetStocks->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Current Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetStocks->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        buttonPortfolio->setText(QCoreApplication::translate("MainWindow", "View Portfolio", nullptr));
        buttonTrade->setText(QCoreApplication::translate("MainWindow", "Buy/Sell Page", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; font-weight:700;\">Portfolio</span></p></body></html>", nullptr));
        userNameLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Welcome! </span></p></body></html>", nullptr));
        label_5->setText(QString());
        buttonDashboard->setText(QCoreApplication::translate("MainWindow", "Go to Dashboard", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700;\">Trading Page</span></p></body></html>", nullptr));
        labelSelectedStock->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700;\">TextLabel</span></p></body></html>", nullptr));
        buyButton->setText(QCoreApplication::translate("MainWindow", "Buy", nullptr));
        sellButton->setText(QCoreApplication::translate("MainWindow", "Sell", nullptr));
        buttonDashboard_2->setText(QCoreApplication::translate("MainWindow", "Back to Dashboard", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">@ k242554, k242542, k242523</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
