#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <Tutorial.h>
#include <Controller.h>
#include <CSVRepo.h>
#include "TutorialModel.h"

namespace Ui {
    class AdminWindow;
}

class AdminWindow : public QDialog {
Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0, CSVRepo *repo = nullptr, Controller *ctrl = nullptr);

    ~AdminWindow();

private slots:

    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Update_clicked();

    void on_Diagram_clicked();

    void on_undo_clicked();

    void on_redo_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::AdminWindow *ui;
    CSVRepo *repo;
    Controller *ctrl;
    TutorialModel* listModel;

    std::string displayAllTutorialsRepo();

    std::string printTutorial(const Tutorial &t, bool flag);

    void updateList();

};

#endif // ADMINWINDOW_H
