#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QDialog>
#include <CSVRepo.h>

namespace Ui {
    class Diagram;
}

class Diagram : public QDialog
{
Q_OBJECT

public:
    explicit Diagram(QWidget *parent = nullptr, CSVRepo *repo = nullptr);
    ~Diagram();

private:
    Ui::Diagram *ui;

    CSVRepo *repo;
};

#endif // DIAGRAM_H
