
#include "headers/Repo.h"

Repository::Repository() {
    list = new std::vector<List>();
}

Repository::~Repository() {
    delete list;
}

bool Repository::add(const List &t) {
    this->list->push_back(t);
    return true;
}



