#ifndef UI_ADMINADDDIALOG_H
#define UI_ADMINADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AdminAddDialog {
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *presenter;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *title;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTimeEdit *time;
    QSpinBox *views;
    QSpinBox *likes;
    QLabel *label_6;
    QPlainTextEdit *link;

    void setupUi(QDialog *AdminAddDialog) {
        if (AdminAddDialog->objectName().isEmpty())
            AdminAddDialog->setObjectName(QString::fromUtf8("AdminAddDialog"));
        AdminAddDialog->resize(440, 210);

        buttonBox = new QDialogButtonBox(AdminAddDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 170, 340, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

        presenter = new QPlainTextEdit(AdminAddDialog);
        presenter->setObjectName(QString::fromUtf8("presenter"));
        presenter->setEnabled(true);
        presenter->setGeometry(QRect(70, 10, 361, 31));

        label = new QLabel(AdminAddDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 91, 31));

        label_2 = new QLabel(AdminAddDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 91, 31));

        title = new QPlainTextEdit(AdminAddDialog);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(70, 50, 361, 31));

        label_3 = new QLabel(AdminAddDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 130, 91, 31));

        label_4 = new QLabel(AdminAddDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 130, 91, 31));

        label_5 = new QLabel(AdminAddDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 130, 91, 31));

        time = new QTimeEdit(AdminAddDialog);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(340, 130, 91, 31));

        views = new QSpinBox(AdminAddDialog);
        views->setObjectName(QString::fromUtf8("views"));
        views->setGeometry(QRect(190, 130, 91, 31));
        views->setMaximum(99999999);

        likes = new QSpinBox(AdminAddDialog);
        likes->setObjectName(QString::fromUtf8("likes"));
        likes->setGeometry(QRect(50, 130, 91, 31));
        likes->setMaximum(99999999);

        label_6 = new QLabel(AdminAddDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 91, 31));

        link = new QPlainTextEdit(AdminAddDialog);
        link->setObjectName(QString::fromUtf8("link"));
        link->setGeometry(QRect(70, 90, 361, 31));

        retranslateUi(AdminAddDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AdminAddDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AdminAddDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AdminAddDialog);
    } // setupUi

    void retranslateUi(QDialog *AdminAddDialog) {
        AdminAddDialog->setWindowTitle(QApplication::translate("AdminAddDialog", "Add Tutorial", nullptr));
        label->setText(QApplication::translate("AdminAddDialog", "Presenter:", nullptr));
        label_2->setText(QApplication::translate("AdminAddDialog", "Title:", nullptr));
        label_3->setText(QApplication::translate("AdminAddDialog", "Likes:", nullptr));
        label_4->setText(QApplication::translate("AdminAddDialog", "Views:", nullptr));
        label_5->setText(QApplication::translate("AdminAddDialog", "Duration:", nullptr));
        time->setDisplayFormat(QApplication::translate("AdminAddDialog", "mm:ss", nullptr));
        label_6->setText(QApplication::translate("AdminAddDialog", "Link:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminAddDialog : public Ui_AdminAddDialog {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINADDDIALOG_H
