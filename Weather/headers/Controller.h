
#pragma once

#include "Repo.h"
#include "Iterator.h"
#include "FileRepo.h"

class Controller {
    IFileRepo *repo;
    Iterator Iter;
public:
//    Controller(const IFileRepo& r) : repo{ r }, Iter() {}

    bool serializable;
    Controller(IFileRepo *r) : Iter() {
        repo = r;
    };

    Controller(const Controller &c);

    ~Controller();

    bool add(const std::string &desc, const int time_start, const int perc, int time_stop);

};

