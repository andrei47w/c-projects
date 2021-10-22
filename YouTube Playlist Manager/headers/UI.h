//
// Created by Andrei on 4/13/2021.
//

#pragma once

#include "headers/Controller.h"

class UI {
private:
    Controller *ctrl;

public:
    UI(Controller *c);

    ~UI();

    void run();

private:
    static void printMenu();

    static void printRepositoryMenu();

    static void printWatchListMenu();

    void addTutorialToRepo();

    void deleteTutorialFromRepo();

    void updateTutorialFromRepo();

    static void printTemplate();

    static void printWatchlistTemplate();

    void displayAllTutorialsRepo();

    static void printTutorial(const Tutorial &t, bool flag = true);

    void addTutorialToWatchlist();

    void viewWatchlist();

    void display();
};

