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

    [[nodiscard]] Transporter *Clone() const override;


    void setType(const std::string &newType) { type = newType; }
    void setName(const std::string &newName) { name = newName; }
    void setCargoVolume(float new_cargo_volume) { cargo_volume = new_cargo_volume; }
    void setSizeX(float sizeX) { this->sizeX = sizeX; }
    void setSizeY(float sizeY) { this->sizeY = sizeY; }
    void setSizeZ(float sizeZ) { this->sizeZ = sizeZ; }

    void setCities(std::string *cities, int amount_cities);
};
