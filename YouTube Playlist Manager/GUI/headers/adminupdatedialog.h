#ifndef ADMINUPDATEDIALOG_H
#define ADMINUPDATEDIALOG_H

#include <QDialog>

namespace Ui {
    class AdminUpdateDialog;
}

class AdminUpdateDialog : public QDialog {
Q_OBJECT

public:
    explicit AdminUpdateDialog(QWidget *parent = nullptr);

    ~AdminUpdateDialog();

    std::string getOldTitle();

    std::string getOldPres();

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
    Ui::AdminUpdateDialog *ui;
};

#endif // ADMINUPDATEDIALOG_H
