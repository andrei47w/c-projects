#include <iostream>
#include <headers/PlayButtonDelegate.h>
#include "GUI/headers/userwindow.h"
#include "GUI/ui_headers/ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent, CSVRepo *repo, Controller *ctrl) :
        QDialog(parent),
        ui(new Ui::UserWindow) {
    ui->setupUi(this);
    this->repo = repo;
    this->ctrl = ctrl;
    watchlistModel = new TutorialModel{ this->ctrl->getWatchlist() };
    this->updateList();
    this->ctrl->configIterator("");
    ui->textBrowser_2->setText(QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));

    ui->Table->setModel(watchlistModel);

    ui->Table->resizeColumnsToContents();
    ui->Table->resizeColumnToContents(6);

    ui->Table->resizeRowsToContents();

    ui->Table->setItemDelegate(new PlayButtonDelegate{});
    ui->Table->setColumnWidth(0, 100);
    ui->Table->setColumnWidth(1, 250);
    ui->Table->setColumnWidth(2, 70);
    ui->Table->setColumnWidth(3, 70);
    ui->Table->setColumnWidth(4, 95);
    ui->Table->setColumnWidth(5, 70);
    ui->Table->setColumnWidth(6, 40);

}


UserWindow::~UserWindow() {
    this->repo->update_write();
    delete ui;
}

void UserWindow::on_Add_clicked() {
    try {
        this->watchlistModel->addTutorialToRepository(this->ctrl->getCurrentTutorial());
        this->updateList();
    }
    catch (RepositoryException &v) {}

}


void UserWindow::on_Remove_clicked() {
    try {
        this->watchlistModel->removeTutorialFromRepository(this->ctrl->getCurrentTutorial());
        this->updateList();
    }
    catch (RepositoryException &v) {}
}


void UserWindow::on_Like_clicked() {
    this->ctrl->likeTutorial();
    ui->textBrowser_2->setText(QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
    this->repo->update_write();
    try {
        this->ctrl->deleteTutorialFromWatchlist(this->ctrl->getCurrentTutorial());
        this->ctrl->addTutorialToWatchlist(this->ctrl->getCurrentTutorial());
        watchlistModel->likeTutorial(this->ctrl->getCurrentTutorial());
    }
    catch(...){}
    this->updateList();
}


void UserWindow::on_Open_clicked() {
    this->ctrl->getCurrentTutorial().open();
}

void UserWindow::on_OpenList_clicked() {
    this->ctrl->display();
}


void UserWindow::on_Next_clicked() {
    this->ctrl->next();
    ui->textBrowser_2->setText(QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
}

void UserWindow::on_Search_clicked() {
    std::string search = ui->SearchText->toPlainText().toStdString();

    if (search.empty()) {
        this->ctrl->configIterator("");
        ui->textBrowser_2->setText(
                QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
    }
    this->ctrl->configIterator(search);
    if (this->ctrl->getCurrentTutorial().getPresenter().empty()) {
        ui->textBrowser_2->setText("");
        return;
    }
    ui->textBrowser_2->setText(QString::fromUtf8(this->printTutorial(this->ctrl->getCurrentTutorial(), false).c_str()));
}

std::string UserWindow::printTutorial(const Tutorial &t, bool flag) {
    std::string tutorials;

    Duration d = t.getDuration();
    tutorials += "| ";
    tutorials += t.getPresenter();
    for (int i = 1; i <= 18 - t.getPresenter().length(); i++) tutorials += " ";

    tutorials += "| ";
    tutorials += t.getTitle();
    for (int i = 1; i <= 53 - t.getTitle().length(); i++) tutorials += " ";

    tutorials += "| ";
    tutorials += std::to_string(t.getNoLikes());
    int length = 1;
    int x = (int) t.getNoLikes();
    while (x != 0) {
        length++;
        x /= 10;
    }
    for (int i = 1; i <= 7 - length; i++) tutorials += " ";

    tutorials += "| ";
    tutorials += std::to_string(d.getMinutes());
    tutorials += ":";
    tutorials += std::to_string(d.getSeconds());
    length = 1;
    x = (int) d.getMinutes();
    while (x != 0) {
        length++;
        x /= 10;
    }
    x = (int) d.getSeconds();
    while (x != 0) {
        length++;
        x /= 10;
    }
    length++;
    for (int i = 1; i <= 10 - length; i++) tutorials += " ";

    if (flag) {
        tutorials += "| ";
        tutorials += std::to_string(t.getNoViews());
    }
    return tutorials;
}

void UserWindow::updateList() {
//    ui->textBrowser->setText(QString::fromUtf8(this->viewWatchlist().c_str()));
//    ui->Table.

}

std::string UserWindow::viewWatchlist() {
    std::vector<Tutorial> *v = this->ctrl->getWatchlist()->getTutorials();
    std::string list;
    if (v->empty()) {
        list += "There are no tutorials in the watchlist.";
        return list;
    }

    list += "|____PRESENTER______|________________________TITLE_________________________|_LIKES_|_DURATION\n";
    int i = 0;
    for (auto &it : *v) {
        list += this->printTutorial(it, false);
        list += '\n';
        i++;
    }
    return list;
}

void UserWindow::on_undoWatchlist_clicked() {
    watchlistModel->undo();
    ui->Table->reset();
//    configIterator();
//    this->updateCurrentTutorial();
}

void UserWindow::on_redoWatchlist_clicked() {
    watchlistModel->redo();
    ui->Table->reset();
//    configIterator();
//    this->updateCurrentTutorial();

}

void UserWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case (Qt::Key_Z):
            if (event->modifiers()==Qt::ControlModifier)
                this->on_undoWatchlist_clicked();
            break;
        case (Qt::Key_Y):
            if (event->modifiers()==Qt::ControlModifier)
                this->on_redoWatchlist_clicked();
            break;
    }
}