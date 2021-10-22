#include <HTMLRepo.h>
#include "GUI/headers/mainwindow.h"
#include "GUI/ui_headers/ui_mainwindow.h"
#include "GUI/headers/adminwindow.h"
#include "GUI/headers/userwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_Admin_clicked() {
    auto *repo = new CSVRepo("..//input files//tutorials.txt");
    auto *watch = new HTMLRepo("..//input files//watchlist.html");
    auto *ctrl = new Controller(repo, watch);

    AdminWindow *d = new AdminWindow(0, repo, ctrl);
    d->exec();
}


void MainWindow::on_User_clicked() {
    auto *repo = new CSVRepo("..//input files//tutorials.txt");
    IFileRepo *watch = nullptr;
    if(ui->label->text().toStdString() == "HTML")
        watch = new HTMLRepo("..//input files//watchlist.html");
    else watch = new CSVRepo("..//input files//watchlist.csv");
    auto *ctrl = new Controller(repo, watch);

    UserWindow *d = new UserWindow(0, repo, ctrl);
    d->exec();

}

void MainWindow::on_Mode_clicked() {
    if(ui->label->text().toStdString() == "CSV")
        ui->label->setText("HTML");
    else ui->label->setText("CSV");
}


