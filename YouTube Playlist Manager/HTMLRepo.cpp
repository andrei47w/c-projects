//
// Created by Andrei on 4/19/2021.
//

#include "HTMLRepo.h"
#include <fstream>
#include <string>
#include <algorithm>

void HTMLRepo::repoFromFile() {
    std::ifstream inFile(source);
    if (!inFile.is_open())
        throw RepositoryException("Cannot open file: " + source);

    std::string str;
    for (int i = 0; i < 15; i++) getline(inFile, str);

    while (getline(inFile, str)) {
        if (str.find("<tr>") != std::string::npos) {
            getline(inFile, str);
            str.erase(0, 12);
            str.resize(str.find("</td>"));
            std::string presenter = str;

            getline(inFile, str);
            str.erase(0, 12);
            str.resize(str.find("</td>"));
            std::string title = str;

            getline(inFile, str);
            str.erase(0, 12);
            str.resize(str.find("</td>"));
            std::string duration = str;
            str.resize(str.find(':'));
            std::string minutes = str;
            duration.erase(0, str.size() + 1);
            std::string seconds = duration;

            getline(inFile, str);
            str.erase(0, 12);
            str.resize(str.find("</td>"));
            std::string views = str;

            getline(inFile, str);
            str.erase(0, 12);
            str.resize(str.find("</td>"));
            std::string likes = str;

            getline(inFile, str);
            str.erase(0, 21);
            str.resize(str.find("\">Link</a></td>"));
            std::string link = str;

            this->addTutorial(TutorialFactory::MakeTutorial(title, presenter, minutes, seconds, likes, link, views));
        }
    }
    inFile.close();
}

void HTMLRepo::repoToFile() {
    std::ofstream outFile(source);
    std::vector<Tutorial> *s = this->getTutorials();
    std::string type = source;
    type.erase(0, 17);
    type.resize(type.find('.'));

    outFile << "<!DOCTYPE html>\n"
               "<html>\n"
               "<head>\n"
               "    <title>" << type.c_str() << "</title>\n"
                                                "</head>\n"
                                                "<body>\n"
                                                "<table border=\"1\">\n"
                                                "    <tr>\n"
                                                "        <td>Presenter</td>\n"
                                                "        <td>Title</td>\n"
                                                "        <td>Duration</td>\n"
                                                "        <td>Views</td>\n"
                                                "        <td>Likes</td>\n"
                                                "        <td>Link</td>\n"
                                                "    </tr>\n";

    if (!s->empty())
        for (auto &it : *s) {
            outFile << "    <tr>\n";
            outFile << "        <td>" << it.getPresenter().c_str() << "</td>\n";
            outFile << "        <td>" << it.getTitle().c_str() << "</td>\n";
            outFile << "        <td>" << it.getDuration().getMinutes() << ":" << it.getDuration().getSeconds()
                    << "</td>\n";
            outFile << "        <td>" << it.getNoViews() << "</td>\n";
            outFile << "        <td>" << it.getNoLikes() << "</td>\n";
            outFile << "        <td><a href=\"" << it.getSource() << "\">Link</a></td>\n"; // <a href="link">Link</a>
            outFile << "    </tr>\n";
        }
    outFile << "</table>\n"
               "</body>\n"
               "</html>\n";
    outFile.close();
}

HTMLRepo::HTMLRepo(const std::string &source) : IFileRepo(source) {
    if (source.find("watchlist") != std::string::npos) return;
    this->repoFromFile();
}

HTMLRepo::~HTMLRepo() {
    this->repoToFile();
}

void HTMLRepo::display() {
    this->repoToFile();
    std::string s =
            "start chrome \"http://localhost:63342/aidk_916_Popa_Andrei_Calin/input%20files/watchlist.html?_ijt=60qtnj21n7paivdeeco8jeva7p" + source + "\"";
    system(s.c_str());
}

