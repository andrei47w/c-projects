#include "GUI/headers/adminupdatedialog.h"
#include "GUI/ui_headers/ui_adminupdatedialog.h"
#include <string.h>

AdminUpdateDialog::AdminUpdateDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AdminUpdateDialog) {
    ui->setupUi(this);
}

AdminUpdateDialog::~AdminUpdateDialog() {
    delete ui;
}


void AdminUpdateDialog::on_buttonBox_accepted() {
    std::string presenter = ui->presener->toPlainText().toStdString();
    std::string title = ui->title->toPlainText().toStdString();
    std::string new_presenter = ui->new_presenter->toPlainText().toStdString();
    std::string new_tile = ui->new_title->toPlainText().toStdString();
    std::string new_link = ui->new_link->toPlainText().toStdString();
    int seconds = ui->new_time->time().second();
    int minutes = ui->new_time->time().minute();
    int views = ui->new_views->value();
    int likes = ui->new_likes->value();
}

std::string AdminUpdateDialog::getOldTitle() {
    return ui->title->toPlainText().toStdString();
}

std::string AdminUpdateDialog::getOldPres() {
    return ui->presener->toPlainText().toStdString();
}

std::string AdminUpdateDialog::getTitle() {
    return ui->new_title->toPlainText().toStdString();
}

std::string AdminUpdateDialog::getPres() {
    return ui->new_presenter->toPlainText().toStdString();
}

std::string AdminUpdateDialog::getLink() {
    return ui->new_link->toPlainText().toStdString();
}

int AdminUpdateDialog::getMinutes() {
    return ui->new_time->time().minute();
}

int AdminUpdateDialog::getSeconds() {
    return ui->new_time->time().second();
}

int AdminUpdateDialog::getLikes() {
    return ui->new_likes->value();
}

int AdminUpdateDialog::getViews() {
    return ui->new_views->value();
}

