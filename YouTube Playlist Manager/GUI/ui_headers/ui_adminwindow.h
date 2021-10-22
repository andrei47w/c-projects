#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QTableView>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow {
public:
    QPushButton *Add;
    QPushButton *Remove;
    QPushButton *Update;
    QPushButton *Diagram;
    QPushButton *undo;
    QPushButton *redo;
    QTableView *Table;

    void setupUi(QDialog *AdminWindow) {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(720, 480);

        Add = new QPushButton(AdminWindow);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(10, 450, 80, 21));

        Remove = new QPushButton(AdminWindow);
        Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->setGeometry(QRect(100, 450, 80, 21));

        Update = new QPushButton(AdminWindow);
        Update->setObjectName(QString::fromUtf8("Update"));
        Update->setGeometry(QRect(190, 450, 80, 21));

        Diagram = new QPushButton(AdminWindow);
        Diagram->setObjectName(QString::fromUtf8("Diagram"));
        Diagram->setGeometry(QRect(630, 450, 80, 21));

        undo = new QPushButton(AdminWindow);
        undo->setObjectName(QString::fromUtf8("undo"));
        undo->setGeometry(QRect(540, 450, 80, 21));

        redo = new QPushButton(AdminWindow);
        redo->setObjectName(QString::fromUtf8("redo"));
        redo->setGeometry(QRect(450, 450, 80, 21));

        QFont font;
        font.setPointSize(8);
        font.setFamily(QString::fromUtf8("Consolas"));

        Table = new QTableView(AdminWindow);
        Table->setObjectName(QString::fromUtf8("listView"));
        Table->setGeometry(QRect(10, 10, 701, 431));
        Table->setSelectionMode(QAbstractItemView::ContiguousSelection);
        Table->setSelectionBehavior(QAbstractItemView::SelectRows);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow) {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Admin Mode", nullptr));
        Add->setText(QApplication::translate("AdminWindow", "Add", nullptr));
        Remove->setText(QApplication::translate("AdminWindow", "Remove", nullptr));
        Update->setText(QApplication::translate("AdminWindow", "Update", nullptr));
        Diagram->setText(QApplication::translate("AdminWindow", "Diagram", nullptr));
        redo->setText(QApplication::translate("AdminWindow", "Redo", nullptr));
        undo->setText(QApplication::translate("AdminWindow", "Undo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow : public Ui_AdminWindow {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
