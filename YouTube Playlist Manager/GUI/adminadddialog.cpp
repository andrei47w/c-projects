#include "GUI/headers/adminadddialog.h"
#include "GUI/ui_headers/ui_adminadddialog.h"
#include <string.h>
#include <Tutorial.h>


AdminAddDialog::AdminAddDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AdminAddDialog) {
    ui->setupUi(this);
}

AdminAddDialog::~AdminAddDialog() {
    delete ui;
}

void AdminAddDialog::on_buttonBox_accepted() {
//    std::string presenter = ui->presenter->toPlainText().toStdString();
//    std::string tile = ui->title->toPlainText().toStdString();
//    std::string link = ui->link->toPlainText().toStdString();
//    int seconds = ui->time->time().second();
//    int minutes = ui->time->time().minute();
//    int views = ui->views->value();
//    int likes = ui->likes->value();
}

std::string AdminAddDialog::getTitle() {
    return ui->title->toPlainText().toStdString();
}

std::string AdminAddDialog::getPres() {
    return ui->presenter->toPlainText().toStdString();
}

std::string AdminAddDialog::getLink() {
    return ui->link->toPlainText().toStdString();
}

int AdminAddDialog::getMinutes() {
    return ui->time->time().minute();
}

int AdminAddDialog::getSeconds() {
    return ui->time->time().second();
}

int AdminAddDialog::getLikes() {
    return ui->likes->value();
}

int AdminAddDialog::getViews() {
    return ui->views->value();
}





