
#pragma once
#pragma once

#include <iostream>


class List {
private:
    std::string desc;
    int time_start;
    int perc;
    long time_stop;
public:
    // default constructor
    List();

    // constructor
    List(const std::string &desc,
         const int &time_start, const int &perc, const int &time_stop);

    std::string getDesc() const { return desc; }

    int getPerc() const { return perc; }

    int getTimeStart() const { return time_start; }

    int getTimeStop() const { return time_stop; }

    bool operator<(int value);

    friend std::ostream &operator<<(std::ostream &out, const List &t);

    friend std::istream &operator>>(std::istream &in, List &t);

};
