//
// Created by Andrei on 4/13/2021.
//

#include <iostream>
#include "headers/UI.h"
#include <crtdbg.h>
#include <string>
#include <fstream>
#include "headers/CSVRepo.h"
#include "headers/Tests.h"
#include "GUI/headers/mainwindow.h"
#include <QApplication>
#include <HTMLRepo.h>
#include <QFile>
#include <QTextStream>


int main(int argc, char *argv[]){
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QApplication::exec();
}



//
//    int main(int argc, char *argv[])
//    {
//        QApplication app(argc, argv);
//
//        // set stylesheet
//        QFile file(":/dark.qss");
//        file.open(QFile::ReadOnly | QFile::Text);
//        QTextStream stream(&file);
//        app.setStyleSheet(stream.readAll());
//
//        // code goes here
//
//        return app.exec();
//    }


    return 0;
}
