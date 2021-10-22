//
// Created by Andrei on 4/13/2021.
//

#pragma once
#include "IFileRepo.h"

class CSVRepo : public IFileRepo {
protected:
	void repoFromFile() override;
	void repoToFile() override;

public:

	CSVRepo(const std::string& source);
	~CSVRepo();
    void display() override;

    void update_write();

};