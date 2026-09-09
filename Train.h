#pragma once
#include "Transporter.h"
#include <string>
#include <iostream>

class Train : public Transporter {
private:
    std::string name;
    int year_release;
    std::string *path;
    int amount_points;
    int amount_bags;
    float cargo_volume;

public:
    Train();

    Train(const std::string &name, int year_release, const std::string *path, int amount_points, int amount_bags,
          float cargo_volume);

    Train(const Train &other);

    ~Train() override;

    Train &operator=(const Train &other);


    void PrintData() override;

    std::string GetWriteToFileData() override;
};
