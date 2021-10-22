//
// Created by Andrei on 4/19/2021.
//

#pragma once
#include "IFileRepo.h"

class HTMLRepo : public IFileRepo {
protected:
    void repoFromFile() override;
    void repoToFile() override;

public:
    HTMLRepo(const std::string& source);
    ~HTMLRepo();
    void display() override;
};