#ifndef UI_MainWindow_H
#define UI_MainWindow_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QTableView>
#include <QTimeEdit>
#include <QTableWidget>
#include <QDateTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
    //id, description and location.
    QWidget *centralwidget;
    QLabel *profit;
    QPushButton *Update;
    QLineEdit *weight;
    QDateTimeEdit *time;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QTableWidget *table;

    void setupUi(QMainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        profit = new QLabel(centralwidget);
        profit->setObjectName(QString::fromUtf8("revised_files"));
        profit->setGeometry(QRect(10, 10, 131, 21));

        Update = new QPushButton(centralwidget);
        Update->setObjectName(QString::fromUtf8("Update"));
        Update->setGeometry(QRect(350, 410, 80, 21));

        time = new QDateTimeEdit(centralwidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(450, 410, 130, 21));

        weight = new QLineEdit(centralwidget);
        weight->setObjectName(QString::fromUtf8("File_loc"));
        weight->setGeometry(QRect(595, 410, 110, 21));

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        table = new QTableWidget(centralwidget);
        table->setObjectName(QString::fromUtf8("tableView"));
        table->setGeometry(QRect(10, 40, 701, 361));
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setSortingEnabled(true);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Parking App", nullptr));
        profit->setText(QApplication::translate("MainWindow", "Profit: ", nullptr));
        weight->insert("weight");
        Update->setText(QApplication::translate("MainWindow", "Update", nullptr));
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        time->setDisplayFormat("dd/MM hh:mm");
        time->setDateTime(QDateTime::currentDateTime());
    } // retranslateUi

};

namespace Ui {
    class MainWindow : public Ui_MainWindow {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MainWindow_H
