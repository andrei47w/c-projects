//
// Created by Andrei on 4/13/2021.
//

#include "headers/UI.h"
#include <string>
#include <crtdbg.h>
#include "headers/Tests.h"
#include "headers/Validator.h"


using namespace std;

void UI::printMenu() {
    cout << endl;
    cout << "____________________MENU_____________________" << endl;
    cout << "\t 1 - ADMIN mode" << endl;
    cout << "\t 2 - USER mode" << endl;
    cout << "\t 3 - Run tests" << endl;
    cout << "\t 0 - Exit" << endl;
    cout << "_____________________________________________" << endl;
}

void UI::printRepositoryMenu() {
    cout << endl << "_________________COMMANDS__________________" << endl;
    cout << "\t 1 - Add tutorial" << endl;
    cout << "\t 2 - Print all" << endl;
    cout << "\t 3 - Delete tutorial" << endl;
    cout << "\t 4 - Update tutorial" << endl;
    cout << "\t 0 - Return to main menu" << endl;
    cout << "_____________________________________________" << endl;
}

void UI::printWatchListMenu() {
    cout << endl << "_________________COMMANDS__________________" << endl;
    cout << "\t 1 - Add tutorial to watchlist" << endl;
    cout << "\t 2 - View watchlist" << endl;
    cout << "\t 3 - Delete tutorial from watchlist" << endl;
    cout << "\t 4 - Like tutorial" << endl;
    cout << "\t 5 - Next tutorial" << endl;
    cout << "\t 6 - Display watchlist" << endl;
    cout << "\t 0 - Return to main menu" << endl;
    cout << "_____________________________________________" << endl;
}


void UI::addTutorialToRepo() {
    Tutorial t;
    cout << "Enter the tutorial the following format: presenter,title,likes,views,minutes,seconds,link" << endl;

    try {
        cin >> t;
        if (this->ctrl->addTutorialToRepository(t))
            cout << "Tutorial added successfully!" << endl;
        else
            cout << "Cannot add tutorial";
    }
    catch (RepositoryException &v) {
        cout << v.what() << endl;
    }
    catch (ValidationException &v) {
        cout << v.what() << endl;
    }
}

void UI::deleteTutorialFromRepo() {
    cout << "Enter the presenter: ";
    std::string presenter;
    getline(cin, presenter);
    cout << "Enter the title: ";
    std::string title;
    getline(cin, title);
    try {
        if (this->ctrl->removeTutorialFromRepository(presenter, title))
            cout << "The tutorial was removed successfully!" << endl;
    }
    catch (RepositoryException &r) {
        cout << r.what() << endl;
    }
}

void UI::updateTutorialFromRepo() {
    cout << "Enter the presenter: ";
    std::string presenter;
    getline(cin, presenter);
    cout << "Enter the title: ";
    std::string title;
    getline(cin, title);
    cout << "Enter the new updated tutorial\n";
    cout << "Enter the tutorial the following format: presenter,title,likes,views,minutes,seconds,link" << endl;
    Tutorial t;
    cin >> t;
    try {
        if (this->ctrl->updateTutorialFromRepository(presenter, title, t))
            cout << "Tutorial updated successfully!" << endl;
        else
            cout << "Cannot update_write tutorial!"
                 << endl;
    }
    catch (RepositoryException &v) {
        cout << v.what() << endl;
    }
    catch (ValidationException &v) {
        cout << v.what() << endl;
    }


}

void UI::printTemplate() {
    cout << endl
         << "NO.|____PRESENTER______|________________________TITLE_________________________|_LIKES_|_DURATION_|_VIEWS"
         << endl;
}

void UI::printWatchlistTemplate() {
    cout << endl
         << "|____PRESENTER______|________________________TITLE_________________________|_LIKES_|_DURATION"
         << endl;
}

void UI::displayAllTutorialsRepo() {
    std::vector<Tutorial> *v = this->ctrl->getRepo()->getTutorials();
    if (v->empty()) {
        cout << "There are no tutorials in the repository." << endl;
        return;
    }

    this->printTemplate();
    int i = 1;
    for (auto &it : *v) {
        cout << i << "  ";
        UI::printTutorial(it, true);
        i++;
    }
}

void UI::printTutorial(const Tutorial &t, bool flag) {
    Duration d = t.getDuration();
    cout << "| " << t.getPresenter();
    for (int i = 1; i <= 18 - t.getPresenter().length(); i++) cout << " ";

    cout << "| " << t.getTitle();
    for (int i = 1; i <= 53 - t.getTitle().length(); i++) cout << " ";

    cout << "| " << t.getNoLikes();
    int length = 1;
    int x = (int) t.getNoLikes();
    while (x != 0) {
        length++;
        x /= 10;
    }
    for (int i = 1; i <= 7 - length; i++) cout << " ";

    cout << "| " << d.getMinutes() << ":" << d.getSeconds();
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
    for (int i = 1; i <= 10 - length; i++) cout << " ";

    flag && cout << "| " << t.getNoViews();
    cout << endl;
}

void UI::addTutorialToWatchlist() {
    try {
        this->ctrl->addTutorialToWatchlist(this->ctrl->getCurrentTutorial());
    }
    catch (RepositoryException &v) {
        cout << "Tutorial already added to watchlist" << endl;
    }
}

void UI::viewWatchlist() {
    std::vector<Tutorial> *v = this->ctrl->getWatchlist()->getTutorials();
    if (v->empty()) {
        cout << "There are no tutorials in the watchlist." << endl;
        return;
    }

    this->printWatchlistTemplate();
    int i = 0;
    for (auto &it : *v) {
        this->printTutorial(it, false);
        i++;
    }
}

void UI::display() {
    this->ctrl->display();
}

UI::UI(Controller *c) {
    ctrl = c;
}

UI::~UI() {
    delete ctrl;
}

void UI::run() {
    cin.ignore();
    while (true) {
        int command{0};
        std::string comm;
        UI::printMenu();
        cout << "Input command: ";
        getline(cin, comm);
        try {
            command = Validator::strToInt(comm);
        }
        catch (ValidationException &v) {
            cout << "Command error: " << v.what();
            continue;
        }
        if (command == 0)
            break;

        // repository
        if (command == 1) {
            while (true) {
                UI::printRepositoryMenu();
                int commandRepo{0};
                std::string comm;
                cout << "Input command: ";
                getline(cin, comm);
                try {
                    commandRepo = Validator::strToInt(comm);
                }
                catch (ValidationException &v) {
                    cout << "Command error: " << v.what();
                }

                if (commandRepo == 0)
                    break;
                switch (commandRepo) {
                    case 1:
                        this->addTutorialToRepo();
                        break;
                    case 2:
                        this->displayAllTutorialsRepo();
                        break;
                    case 3:
                        this->deleteTutorialFromRepo();
                        break;
                    case 4:
                        this->updateTutorialFromRepo();
                        break;
                }
            }
        }

        // watchlist
        if (command == 2) {
            std::string presenter{};
            cout << "What presenter would you like to watch? (give no input to parse through all tutorials)";
            getline(cin, presenter);
            this->ctrl->configIterator(presenter);
            if (!this->ctrl->getCurrentTutorial().getPresenter().empty()) {
                this->printWatchlistTemplate();
                this->ctrl->startIteration();
                printTutorial(this->ctrl->getCurrentTutorial(), false);
            } else {
                cout << "No tutorial with that presenter exists" << endl;
                continue;
            }
            cout << endl;
            while (true) {
                UI::printWatchListMenu();
                int commandPlaylist{0};
                std::string comm;
                cout << "Input command: ";
                getline(cin, comm);
                try {
                    commandPlaylist = Validator::strToInt(comm);
                }
                catch (ValidationException &v) {
                    cout << "Command error: " << v.what();
                }
                if (commandPlaylist == 0)
                    break;
                switch (commandPlaylist) {
                    case 1:
                        this->addTutorialToWatchlist();
                        break;
                    case 2:
                        this->viewWatchlist();
                        break;
                    case 3: {
                        try {

                            if (this->ctrl->deleteTutorialFromWatchlist(this->ctrl->getCurrentTutorial()))
                                cout << "Tutorial deleted from watchlist" << endl;
                            else
                                cout << "Tutorial is not in playlist" << endl;
                            break;
                        }
                        catch (RepositoryException &v) {
                            cout << "The tutorial is not in playlist" << endl;
                        }
                    }
                    case 5: {
                        this->ctrl->next();
                        this->printWatchlistTemplate();
                        this->printTutorial(this->ctrl->getCurrentTutorial(), false);
                        break;
                    }
                    case 4: {
                        this->ctrl->likeTutorial();
                        break;
                    }
                    case 6: {
                        this->display();
                        break;
                    }
                }
            }
        }
        if (command == 3) {
            testMain();
            cout << "Tests were successful!";
        }
    }
}