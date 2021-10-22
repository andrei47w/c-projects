#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QPlainTextEdit>
#include <QAbstractTableModel>
#include <QTableView>

QT_BEGIN_NAMESPACE

class Ui_UserWindow {
public:
    QPushButton *Add;
    QPushButton *Remove;
    QPushButton *Like;
    QPushButton *Next;
    QPushButton *Open;
    QPushButton *OpenList;
    QPushButton *Search;
//    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QPlainTextEdit *SearchText;
    QTableView *Table;
    QPushButton *undoWatchlist;
    QPushButton *redoWatchlist;

    void setupUi(QDialog *UserWindow) {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(720, 480);
        Add = new QPushButton(UserWindow);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(10, 450, 60, 21));

        Remove = new QPushButton(UserWindow);
        Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->setGeometry(QRect(79, 450, 60, 21));

        Like = new QPushButton(UserWindow);
        Like->setObjectName(QString::fromUtf8("Like"));
        Like->setGeometry(QRect(149, 450, 60, 21));

        Next = new QPushButton(UserWindow);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setGeometry(QRect(630, 450, 80, 21));

        Open = new QPushButton(UserWindow);
        Open->setObjectName(QString::fromUtf8("Open"));
        Open->setGeometry(QRect(219, 450, 80, 21));

        OpenList = new QPushButton(UserWindow);
        OpenList->setObjectName(QString::fromUtf8("OpenList"));
        OpenList->setGeometry(QRect(309, 450, 80, 21));

        Search = new QPushButton(UserWindow);
        Search->setObjectName(QString::fromUtf8("Search"));
        Search->setGeometry(QRect(399, 450, 80, 21));

        Table = new QTableView(UserWindow);
        Table->setObjectName(QStringLiteral("watchlistView"));
        Table->setObjectName(QString::fromUtf8("textBrowser"));
        Table->setGeometry(QRect(10, 10, 701, 391));
        Table->setSelectionMode(QAbstractItemView::ContiguousSelection);
        Table->setSelectionBehavior(QAbstractItemView::SelectRows);

        textBrowser_2 = new QTextBrowser(UserWindow);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 411, 570, 24));

        SearchText = new QPlainTextEdit(UserWindow);
        SearchText->setObjectName(QString::fromUtf8("new_link"));
        SearchText->setGeometry(QRect(489, 448, 132, 24));

        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        Table->setFont(font);
        textBrowser_2->setFont(font);

        undoWatchlist = new QPushButton(UserWindow);
        undoWatchlist->setObjectName(QStringLiteral("undoWatchlist"));
        undoWatchlist->setGeometry(QRect(585, 411, 60, 24));

        redoWatchlist = new QPushButton(UserWindow);
        redoWatchlist->setObjectName(QStringLiteral("redoWatchlist"));
        redoWatchlist->setGeometry(QRect(650, 411, 60, 24));

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QDialog *UserWindow) {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "User Mode", nullptr));
        Add->setText(QApplication::translate("UserWindow", "Add", nullptr));
        Remove->setText(QApplication::translate("UserWindow", "Remove", nullptr));
        Like->setText(QApplication::translate("UserWindow", "Like", nullptr));
        Next->setText(QApplication::translate("UserWindow", "Next", nullptr));
        Open->setText(QApplication::translate("UserWindow", "Open Tutorial", nullptr));
        OpenList->setText(QApplication::translate("UserWindow", "Open List", nullptr));
        Search->setText(QApplication::translate("UserWindow", "Search", nullptr));
        undoWatchlist->setText(QApplication::translate("UserWindow", "Undo", nullptr));
        redoWatchlist->setText(QApplication::translate("UserWindow", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow : public Ui_UserWindow {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
