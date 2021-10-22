//
// Created by Andrei on 5/24/2021.
//

#pragma once

#include <string>
#include "IFileRepo.h"

class FileRepo : public IFileRepo {
protected:
    void repoFromFile() override;
    void repoToFile() override;

public:

    FileRepo(const std::string& source);
    ~FileRepo();
    void display();

    void update_write();

};