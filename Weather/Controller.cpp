
#include "headers/Controller.h"

Controller::Controller(const Controller &c) {
    repo = c.repo;
}

Controller::~Controller() {
    delete repo;
}

bool Controller::add(const std::string& desc, const int tine_start, int perc, const int time_stop)
{
    List t{desc, tine_start, perc, time_stop };
    return this->repo->add(t);
}
