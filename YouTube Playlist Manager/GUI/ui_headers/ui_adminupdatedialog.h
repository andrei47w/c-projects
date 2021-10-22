#ifndef UI_ADMINUPDATEDIALOG_H
#define UI_ADMINUPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AdminUpdateDialog {
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *label;
    QPlainTextEdit *presener;
    QPlainTextEdit *title;
    QLabel *label_6;
    QSpinBox *new_views;
    QPlainTextEdit *new_link;
    QLabel *label_3;
    QPlainTextEdit *new_title;
    QSpinBox *new_likes;
    QPlainTextEdit *new_presenter;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QTimeEdit *new_time;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QDialog *AdminUpdateDialog) {
        if (AdminUpdateDialog->objectName().isEmpty())
            AdminUpdateDialog->setObjectName(QString::fromUtf8("AdminUpdateDialog"));
        AdminUpdateDialog->resize(440, 320);

        buttonBox = new QDialogButtonBox(AdminUpdateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 280, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

        label_2 = new QLabel(AdminUpdateDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 81, 31));

        label = new QLabel(AdminUpdateDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 31));

        presener = new QPlainTextEdit(AdminUpdateDialog);
        presener->setObjectName(QString::fromUtf8("presener"));
        presener->setGeometry(QRect(70, 10, 361, 31));

        title = new QPlainTextEdit(AdminUpdateDialog);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(70, 50, 361, 31));

        label_6 = new QLabel(AdminUpdateDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 200, 91, 31));

        new_views = new QSpinBox(AdminUpdateDialog);
        new_views->setObjectName(QString::fromUtf8("new_views"));
        new_views->setGeometry(QRect(190, 240, 91, 31));
        new_views->setMaximum(99999999);

        new_link = new QPlainTextEdit(AdminUpdateDialog);
        new_link->setObjectName(QString::fromUtf8("new_link"));
        new_link->setGeometry(QRect(70, 200, 361, 31));

        label_3 = new QLabel(AdminUpdateDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 91, 31));

        new_title = new QPlainTextEdit(AdminUpdateDialog);
        new_title->setObjectName(QString::fromUtf8("new_title"));
        new_title->setGeometry(QRect(70, 160, 361, 31));

        new_likes = new QSpinBox(AdminUpdateDialog);
        new_likes->setObjectName(QString::fromUtf8("new_likes"));
        new_likes->setGeometry(QRect(50, 240, 91, 31));
        new_likes->setMaximum(99999999);

        new_presenter = new QPlainTextEdit(AdminUpdateDialog);
        new_presenter->setObjectName(QString::fromUtf8("new_presenter"));
        new_presenter->setGeometry(QRect(70, 120, 361, 31));

        label_4 = new QLabel(AdminUpdateDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 160, 91, 31));

        label_5 = new QLabel(AdminUpdateDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 240, 91, 31));

        label_7 = new QLabel(AdminUpdateDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(290, 240, 91, 31));

        new_time = new QTimeEdit(AdminUpdateDialog);
        new_time->setObjectName(QString::fromUtf8("new_time"));
        new_time->setGeometry(QRect(340, 240, 91, 31));
        new_time->setCurrentSection(QDateTimeEdit::MinuteSection);

        label_8 = new QLabel(AdminUpdateDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(150, 240, 91, 31));

        label_9 = new QLabel(AdminUpdateDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 90, 111, 31));

        retranslateUi(AdminUpdateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AdminUpdateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AdminUpdateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AdminUpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *AdminUpdateDialog) {
        AdminUpdateDialog->setWindowTitle(QApplication::translate("AdminUpdateDialog", "Update Tutorial", nullptr));
        label_2->setText(QApplication::translate("AdminUpdateDialog", "Title:", nullptr));
        label->setText(QApplication::translate("AdminUpdateDialog", "Presenter:", nullptr));
        label_6->setText(QApplication::translate("AdminUpdateDialog", "Link:", nullptr));
        label_3->setText(QApplication::translate("AdminUpdateDialog", "Presenter:", nullptr));
        label_4->setText(QApplication::translate("AdminUpdateDialog", "Title:", nullptr));
        label_5->setText(QApplication::translate("AdminUpdateDialog", "Likes:", nullptr));
        label_7->setText(QApplication::translate("AdminUpdateDialog", "Duration:", nullptr));
        new_time->setDisplayFormat(QApplication::translate("AdminUpdateDialog", "mm:ss", nullptr));
        label_8->setText(QApplication::translate("AdminUpdateDialog", "Views:", nullptr));
        label_9->setText(QApplication::translate("AdminUpdateDialog", "Give the new values:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminUpdateDialog : public Ui_AdminUpdateDialog {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINUPDATEDIALOG_H
