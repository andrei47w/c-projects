
#include "headers/Iterator.h"

Iterator::Iterator() {
    this->current = 0;
}

void Iterator::add(const List &tut) {
    this->tutorials.push_back(tut);
}

List Iterator::getCurrent() {
    if (this->current == this->tutorials.size())
        this->current = 0;
    return this->tutorials[this->current];
}

void Iterator::open() {
    if (this->tutorials.size() == 0)
        return;
    this->current = 0;
    List currentTutorial = this->getCurrent();
}

void Iterator::next() {
    if (this->tutorials.size() == 0)
        return;

    this->current++;
    List currentTut = this->getCurrent();
}

bool Iterator::isEmpty() {
    return this->tutorials.size() == 0;
}

