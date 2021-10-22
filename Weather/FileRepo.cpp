//
// Created by Andrei on 5/24/2021.
//

#include "FileRepo.h"
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "List.h"

void FileRepo::repoFromFile() {
    std::ifstream infile(source);
    List t;
    while (infile >> t) {
        this->add(t);
    }
    infile.close();
}

void FileRepo::repoToFile() {
    std::ofstream outFile(source);
    std::vector<List> *s = this->getList();
    for (auto &it : *s)
        outFile << it << std::endl;
    outFile.close();
}

FileRepo::FileRepo(const std::string &source) : IFileRepo(source) {
    if (source.find("watchlist") != std::string::npos) return;
    this->repoFromFile();
}

FileRepo::~FileRepo() {
    this->repoToFile();
}

void FileRepo::update_write() {
    this->repoToFile();
}

void FileRepo::display()
{   this->repoToFile();
    std::string s = "notepad \"" + source + "\"";
    system(s.c_str());
}
