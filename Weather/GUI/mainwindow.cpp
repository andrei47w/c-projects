#include <IFileRepo.h>
#include <FileRepo.h>
#include <Controller.h>
#include "headers/mainwindow.h"
#include "ui_headers/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    FileRepo *repo = new FileRepo("..//input.txt");
    auto *ctrl = new Controller(repo);

    ui->setupUi(this);
    std::vector<List> *v = repo->getList();
    int i = 0;
    for (auto &it : *v) {
        QString str = QString::number(it.getTimeStart()) + "   " + QString::number(it.getTimeStop()) + "   " +
                      QString::number(it.getPerc()) + "%   " + QString::fromStdString(it.getDesc());
        ui->listWidget->addItem(str);
        i++;
    }
}

MainWindow::~MainWindow(){
    delete ui;
}


