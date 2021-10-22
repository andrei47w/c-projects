#include "GUI/headers/adminremovedialog.h"
#include "GUI/ui_headers/ui_adminremovedialog.h"
#include <string.h>

AdminRemoveDialog::AdminRemoveDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AdminRemoveDialog) {
    ui->setupUi(this);
}

AdminRemoveDialog::~AdminRemoveDialog() {
    delete ui;
}

void AdminRemoveDialog::on_buttonBox_accepted() {
//    std::string presenter = ui->presenter->toPlainText().toStdString();
//    std::string title = ui->title->toPlainText().toStdString();
}

std::string AdminRemoveDialog::getTitle() {
    return ui->title->toPlainText().toStdString();
}

std::string AdminRemoveDialog::getPres() {
    return ui->presenter->toPlainText().toStdString();
}

