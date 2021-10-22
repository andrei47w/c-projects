//
// Created by Andrei on 4/13/2021.
//

#pragma once

#include "Repo.h"

// Our interface for creating repos that read and write to a specific type
class IFileRepo : public Repository {
protected:
    std::string source;

    // pure abstract methods used for writing and reading a file
    virtual void repoFromFile() = 0;

    virtual void repoToFile() = 0;

public:

    IFileRepo(const std::string &source) : Repository(), source(source) {}

    IFileRepo(const IFileRepo &fl) : Repository(fl), source(fl.source) {}

    virtual    ~IFileRepo() = default;

    virtual void display() = 0;
};