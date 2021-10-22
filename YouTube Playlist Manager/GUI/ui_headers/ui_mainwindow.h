#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>


QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
    QWidget *centralwidget;
    QPushButton *Admin;
    QPushButton *User;
//    QPushButton *CSVMode;
    QPushButton *Mode;
    QMenuBar *menubar;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow) {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 480);
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        MainWindow->setFont(font);

        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));

        Admin = new QPushButton(centralwidget);
        Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->setGeometry(QRect(210, 150, 300, 80));

        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferAntialias);
        Admin->setFont(font1);

        User = new QPushButton(centralwidget);
        User->setObjectName(QString::fromUtf8("User"));
        User->setGeometry(QRect(210, 240, 300, 80));
        User->setFont(font1);

//        CSVMode = new QPushButton(centralwidget);
//        CSVMode->setObjectName(QString::fromUtf8("CSVMode"));
//        CSVMode->setGeometry(QRect(210, 330, 145, 40));
//        CSVMode->setFont(font1);

        Mode = new QPushButton(centralwidget);
        Mode->setObjectName(QString::fromUtf8("Mode"));
        Mode->setGeometry(QRect(365, 330, 145, 40));
        Mode->setFont(font1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 720, 20));
        MainWindow->setMenuBar(menubar);

        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 330, 145, 40));
        label->setFont(font1);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Main Menu", nullptr));
        Admin->setText(QApplication::translate("MainWindow", "Administrator Mode", nullptr));
        User->setText(QApplication::translate("MainWindow", "User Mode", nullptr));
        Mode->setText(QApplication::translate("MainWindow", "Switch", nullptr));
        label->setText(QApplication::translate("MainWindow", "CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow : public Ui_MainWindow {
    };
} // namespace Ui

QT_END_NAMESPACE


#endif // UI_MAINWINDOW_H
