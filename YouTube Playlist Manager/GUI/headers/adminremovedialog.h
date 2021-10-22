#ifndef ADMINREMOVEDIALOG_H
#define ADMINREMOVEDIALOG_H

#include <QDialog>

namespace Ui {
    class AdminRemoveDialog;
}

class AdminRemoveDialog : public QDialog {
Q_OBJECT


public:
    explicit AdminRemoveDialog(QWidget *parent = nullptr);

    ~AdminRemoveDialog();

    std::string getPres();

    std::string getTitle();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::AdminRemoveDialog *ui;
};

#endif // ADMINREMOVEDIALOG_H
