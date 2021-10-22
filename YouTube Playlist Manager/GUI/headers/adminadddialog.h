#ifndef ADMINADDDIALOG_H
#define ADMINADDDIALOG_H

#include <QDialog>

namespace Ui {
    class AdminAddDialog;
}

class AdminAddDialog : public QDialog {
Q_OBJECT

public:
    explicit AdminAddDialog(QWidget *parent = nullptr);

    ~AdminAddDialog();

    std::string getTitle();

    std::string getPres();

    int getLikes();

    int getViews();

    std::string getLink();

    int getMinutes();

    int getSeconds();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::AdminAddDialog *ui;
};

#endif // ADMINADDDIALOG_H
