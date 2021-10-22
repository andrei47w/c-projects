#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <QMessageBox>
#include "repo.h"

//TM-96-xyz : 1.85, 2.6, 1.35, 1250, 10D07 9-20, 10D07 11-45
//SB-44-adj : 2.80, 4.5, 2.8, 4250, 10D07 8-20, 10D07 18-45


std::ostream &operator<<(std::ostream &out, const Date &d) {
    out << d.day << " " << d.hour << "-" << d.min;

    return out;
}

void Repository::repoFromFile() {
    std::ifstream infile(source);
    if (!infile.is_open()) {
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Could not open file!");
    }

    std::string line;
    while (getline(infile, line)) {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        std::stringstream stream_line(line);
        std::vector<std::string> seglist;
        std::string segment;
        while (std::getline(stream_line, segment, ':')) {
            seglist.push_back(segment);

        }
        std::stringstream stream_line2(seglist[1]);
        std::vector<std::string> seglist2;
        std::string segment2;
        while (std::getline(stream_line2, segment2, ',')) {
            seglist2.push_back(segment2);
        }

        std::string day = seglist2[4];
        day.erase(5);
        std::string hour = seglist2[4];
        hour.erase(0, 5);
        hour.erase(hour.find('-'));
        std::string min = seglist2[4];
        min.erase(0, min.find('-') + 1);
        Date date1 = Date(day, hour, min);

        day = seglist2[5];
        day.erase(5);
        hour = seglist2[5];
        hour.erase(0, 5);
        hour.erase(hour.find('-'));
        min = seglist2[5];
        min.erase(0, min.find('-') + 1);
        Date date2 = Date(day, hour, min);

        add_elem(seglist[0], seglist2[0], seglist2[1], seglist2[2], seglist2[3], date1, date2);
    }

    infile.close();
}

void Repository::repoToFile() {
    std::ofstream outFile(source);
    std::vector<std::vector<std::string>> s = get_elem();
    for (auto &elems : s) {
        outFile << elems[0] << " : " << elems[1] << ", " << elems[2] << ", " << elems[3] << ", " << elems[4] << ", "
                << elems[5] << " " << elems[6] << "-" << elems[7] << ", " << elems[8] << " " << elems[9] << "-"
                << elems[10];
        outFile << '\n';
    }

    outFile.close();
}

Repository::Repository(const std::string &source) {
    this->source = "../" + source;
    this->repoFromFile();
}

Repository::~Repository() {
    this->repoToFile();
}

std::vector<std::vector<std::string>> Repository::get_elem() {
    return elem;
}

void
Repository::add_elem(std::string plate, std::string width, std::string length, std::string height, std::string weight,
                     Date date1, Date date2) {
    std::vector<std::string> f;
    f.push_back(plate);
    f.push_back(width);
    f.push_back(length);
    f.push_back(height);
    f.push_back(weight);
    f.push_back(date1.day);
    f.push_back(date1.hour);
    f.push_back(date1.min);
    f.push_back(date2.day);
    f.push_back(date2.hour);
    f.push_back(date2.min);

    elem.push_back(f);
}


