
#pragma once

#include <vector>
#include "List.h"

class Repository {
private:
    std::vector <List> *list;

public:
    Repository();

    ~Repository();

    Repository(const Repository &r);

    bool add(const List &t);

    std::vector<List> *getList() { return list; }

};