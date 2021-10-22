#include <utility>


#pragma once

class Date {
public:
    Date(std::string day, std::string hour, std::string min) {
        this->day = std::move(day);
        this->min = std::move(min);
        this->hour = std::move(hour);
    }

    std::string day, hour, min;
};


class Repository {
protected:
    std::string source;

    void repoFromFile();

    void repoToFile();

public:
    std::vector<std::vector<std::string>> elem;

    void add_elem(std::string plate, std::string width, std::string length, std::string height, std::string weight,
                  Date date1, Date date2);

    std::vector<std::vector<std::string>> get_elem();

    Repository(const std::string &source);

    ~Repository();
};