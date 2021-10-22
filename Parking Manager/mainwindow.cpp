#include <iostream>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <algorithm>
#include <cctype>
#include <string>
#include <QHeaderView>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    populate_table();
}

MainWindow::~MainWindow() {
    delete ui;
}

char check_vehicle_type(std::string weight, std::string length) {
    if (stoi(weight) < 2700 && std::stof(length) < 5.8) return 'S';
    if (stoi(weight) < 5700 && std::stof(length) < 9.8) return 'M';
    return 'L';
}

void MainWindow::populate_table() {
    ui->table->clear();
    ui->table->setRowCount(0);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table->setColumnCount(8);
    ui->table->setHorizontalHeaderLabels(
            QStringList() << "ID" << "       Licence Plate       " << "      Length      " << "      Width      "
                          << "     Height     " << "     Weight     " << "        Arrives         "
                          << "        Leaves         ");

    for (int i = 0; i < repo.get_elem().size(); i++) {
        int sID = 0, mID = 0, lID = 0;
        int ok = 0;
        if (check_vehicle_type(repo.get_elem()[i][4], repo.get_elem()[i][1]) == 'S' && sMAX != sID) {
            ui->table->insertRow(ui->table->rowCount());
            sID++;
            std::string id = "S-" + std::to_string(sID);
            ui->table->setItem(ui->table->rowCount() - 1, 0,
                               new QTableWidgetItem(QString::fromUtf8(id.c_str())));
            ok = 1;
        } else if (check_vehicle_type(repo.get_elem()[i][4], repo.get_elem()[i][1]) == 'M' && mMAX != mID) {
            ui->table->insertRow(ui->table->rowCount());
            mID++;
            std::string id = "M-" + std::to_string(mID);
            ui->table->setItem(ui->table->rowCount() - 1, 0,
                               new QTableWidgetItem(QString::fromUtf8(id.c_str())));
            ok = 1;
        } else if (check_vehicle_type(repo.get_elem()[i][4], repo.get_elem()[i][1]) == 'L' && lMAX != lID) {
            ui->table->insertRow(ui->table->rowCount());
            lID++;
            std::string id = "L-" + std::to_string(lID);
            ui->table->setItem(ui->table->rowCount() - 1, 0,
                               new QTableWidgetItem(QString::fromUtf8(id.c_str())));
            ok = 1;
        }

        if (ok) {
            ui->table->setItem(ui->table->rowCount() - 1, 1,
                               new QTableWidgetItem(QString::fromUtf8(repo.get_elem()[i][0].c_str())));
            ui->table->setItem(ui->table->rowCount() - 1, 2,
                               new QTableWidgetItem(QString::fromUtf8(repo.get_elem()[i][1].c_str())));
            ui->table->setItem(ui->table->rowCount() - 1, 3,
                               new QTableWidgetItem(QString::fromUtf8(repo.get_elem()[i][2].c_str())));
            ui->table->setItem(ui->table->rowCount() - 1, 4,
                               new QTableWidgetItem(QString::fromUtf8(repo.get_elem()[i][3].c_str())));
            ui->table->setItem(ui->table->rowCount() - 1, 5,
                               new QTableWidgetItem(QString::fromUtf8(repo.get_elem()[i][4].c_str())));
            std::string date = repo.get_elem()[i][5] + " " + repo.get_elem()[i][6] + ":" + repo.get_elem()[i][7];
            ui->table->setItem(ui->table->rowCount() - 1, 6, new QTableWidgetItem(QString::fromUtf8(date.c_str())));
            date = repo.get_elem()[i][8] + " " + repo.get_elem()[i][9] + ":" + repo.get_elem()[i][10];
            ui->table->setItem(ui->table->rowCount() - 1, 7, new QTableWidgetItem(QString::fromUtf8(date.c_str())));
        }
    }
    update_profit();
}

void MainWindow::on_Update_clicked() {
    if (ui->table->selectionModel()->selectedRows().size() <= 0) return;

    std::string weight = ui->weight->text().toUtf8().constData();
    std::string hour = std::to_string(ui->time->time().hour());
    std::string min = std::to_string(ui->time->time().minute());
    std::string day, month, date;
    if (ui->time->date().day() < 10) day = '0' + std::to_string(ui->time->date().day());
    else day = std::to_string(ui->time->date().day());
    if (ui->time->date().day() < 10) month = '0' + std::to_string(ui->time->date().month());
    else month = std::to_string(ui->time->date().month());
    date = day + 'D' + month;

    int row = ui->table->selectionModel()->selectedRows()[0].row();
    repo.elem[row].pop_back();
    repo.elem[row].pop_back();
    repo.elem[row].pop_back();
    repo.elem[row][4] = weight;
    repo.elem[row].push_back(date);
    repo.elem[row].push_back(hour);
    repo.elem[row].push_back(min);

    populate_table();
    update_profit();
}

void MainWindow::update_profit() {
    int profit = 0;
    for (int i = 0; i < repo.get_elem().size(); i++) {
        std::string day1 = repo.get_elem()[i][5];
        day1.erase(2);
        std::string month1 = repo.get_elem()[i][5];
        month1.erase(0, 3);

        std::string day2 = repo.get_elem()[i][8];
        day2.erase(2);
        std::string month2 = repo.get_elem()[i][8];
        month2.erase(0, 3);

        profit += (stoi(day2) - stoi(day1) + (stoi(month2) - stoi(month1)) * 30) * 24 * this->pricePerH +
                  (stoi(repo.get_elem()[i][9]) - stoi(repo.get_elem()[i][6])) * this->pricePerH;
    }
    ui->profit->setText(QString::number(profit));
}