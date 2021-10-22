#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include "repo.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT


private slots:

    void on_Update_clicked();

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void populate_table();

    void update_profit();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int sMAX = 50, mMAX = 20, lMAX = 10, pricePerH = 5;
    Repository repo = Repository("vehicles.txt");
};

#endif // MainWindow_H
