
#include "headers/List.h"
#include <Windows.h>
#include <shellapi.h>
#include <string>
#include "headers/Utils.h"
#include <vector>

using namespace std;

List::List() : desc(""), time_start(int(0)), perc(int(0)), time_stop(0) {}


List::List(const std::string &desc,
           const int &time_start, const int &perc, const int &time_stop) {
    this->desc = desc;
    this->time_start = time_start;
    this->perc = perc;
    this->time_stop = time_stop;
}


bool List::operator<(int value) {
    return this->time_stop < value;
}

std::ostream &operator<<(std::ostream &out, const List &t) {
    out << std::to_string(t.getTimeStart()) << ";" << std::to_string(t.getTimeStop()) << ";" << std::to_string(t.getPerc()) << ";" << t.getDesc().c_str();
    return out;
}

std::istream &operator>>(std::istream &in, List &t) {
    std::string line;
    getline(in, line);
    if (line.size() == 0)
        return in;
    vector<string> tokens = tokenize(line, ';');

    std::cout<<tokens[0]<<" "<<tokens[1]<<" "<<tokens[2]<<" "<<tokens[3]<<'\n';


    t = List(trim(tokens[3]), stoi(trim(tokens[0])), stoi(trim(tokens[2])), stoi(trim(tokens[1])));

    return in;
}