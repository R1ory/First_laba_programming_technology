#pragma once
#include "Transporter.h"
#include <string>
#include <iostream>

class Plane : public Transporter {
private:
    std::string type;
    std::string name;
    float cargo_volume;
    float sizeX, sizeY, sizeZ;
    std::string *cities;
    int amount_cities;

public:
    Plane();

    Plane(const std::string &type, const std::string &name, float cargo_volume, float sizeX, float sizeY, float sizeZ,
          const std::string *cities, int amount_cities);

    Plane(const Plane &other);

    ~Plane() override;

    Plane &operator=(const Plane &other);


    void PrintData() override;

    std::string GetWriteToFileData() override;
};
