#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QDialog>
#include <CSVRepo.h>
#include <Controller.h>
#include "TutorialModel.h"

namespace Ui {
    class UserWindow;
}

class UserWindow : public QDialog {
Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = 0, CSVRepo *repo = nullptr, Controller *ctrl = nullptr);

    ~UserWindow();

private slots:

    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Like_clicked();

    void on_Open_clicked();

    void on_OpenList_clicked();

    void on_Next_clicked();

    void on_Search_clicked();

    void on_undoWatchlist_clicked();

    void on_redoWatchlist_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::UserWindow *ui;
    CSVRepo *repo;
    Controller *ctrl;
    TutorialModel* watchlistModel;

    std::string printTutorial(const Tutorial &t, bool flag);

    void updateList();

    std::string viewWatchlist();
};

#endif // USERWINDOW_H
