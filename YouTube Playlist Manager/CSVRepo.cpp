//
// Created by Andrei on 4/13/2021.
//

#include "headers/CSVRepo.h"
#include <fstream>
#include <stdlib.h>

void CSVRepo::repoFromFile() {
    std::ifstream infile(source);
    if (!infile.is_open())
        throw RepositoryException("Cannot open file: " + source);
    Tutorial t;
    while (infile >> t) {
        this->addTutorial(t);
    }
    infile.close();
}

void CSVRepo::repoToFile() {
    std::ofstream outFile(source);
    std::vector<Tutorial> *s = this->getTutorials();
    for (auto &it : *s)
        outFile << it << std::endl;
    outFile.close();
}

CSVRepo::CSVRepo(const std::string &source) : IFileRepo(source) {
    if (source.find("watchlist") != std::string::npos) return;
    this->repoFromFile();
}

CSVRepo::~CSVRepo() {
    this->repoToFile();
}

void CSVRepo::update_write() {
    this->repoToFile();
}

void CSVRepo::display()
{   this->repoToFile();
    std::string s = "notepad \"" + source + "\"";
    system(s.c_str());
}
