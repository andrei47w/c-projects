
#pragma once

#include <vector>
#include "List.h"

class Iterator {
private:
    std::vector<List> tutorials;
    int current;
public:
    Iterator();

    void add(const List &t);

    List getCurrent();

    void open();

    void next();

    bool isEmpty();

};
