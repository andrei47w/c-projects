#ifndef UI_ADMINREMOVEDIALOG_H
#define UI_ADMINREMOVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AdminRemoveDialog {
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *presenter;
    QPlainTextEdit *title;

    void setupUi(QDialog *AdminRemoveDialog) {
        if (AdminRemoveDialog->objectName().isEmpty())
            AdminRemoveDialog->setObjectName(QString::fromUtf8("AdminRemoveDialog"));
        AdminRemoveDialog->resize(440, 130);

        buttonBox = new QDialogButtonBox(AdminRemoveDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 90, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

        label = new QLabel(AdminRemoveDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 31));

        label_2 = new QLabel(AdminRemoveDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 81, 31));

        presenter = new QPlainTextEdit(AdminRemoveDialog);
        presenter->setObjectName(QString::fromUtf8("presenter"));
        presenter->setGeometry(QRect(70, 10, 361, 31));

        title = new QPlainTextEdit(AdminRemoveDialog);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(70, 50, 361, 31));

        retranslateUi(AdminRemoveDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AdminRemoveDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AdminRemoveDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AdminRemoveDialog);
    } // setupUi

    void retranslateUi(QDialog *AdminRemoveDialog) {
        AdminRemoveDialog->setWindowTitle(QApplication::translate("AdminRemoveDialog", "Remove Tutorial", nullptr));
        label->setText(QApplication::translate("AdminRemoveDialog", "Presenter:", nullptr));
        label_2->setText(QApplication::translate("AdminRemoveDialog", "Title:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminRemoveDialog : public Ui_AdminRemoveDialog {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINREMOVEDIALOG_H
