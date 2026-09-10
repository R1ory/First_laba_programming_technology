#include "Plane.h"

Plane::Plane() {
    type = "Cargo";
    name = "F1";
    cargo_volume = 20000;
    sizeX = 400;
    sizeY = 75;
    sizeZ = 50;
    amount_cities = 2;
    cities = new std::string[amount_cities]{"Moscow", "Paris"};
}

Plane::Plane(const std::string &type, const std::string &name, float cargo_volume, float sizeX, float sizeY,
             float sizeZ, const std::string *cities, int amount_cities) {
    this->type = type;
    this->name = name;
    this->cargo_volume = cargo_volume;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->sizeZ = sizeZ;

    this->amount_cities = amount_cities;
    this->cities = new std::string[amount_cities];
    for (int i = 0; i < amount_cities; i++) {
        this->cities[i] = cities[i];
    }
}

Plane::Plane(const Plane &other) {
    type = other.type;
    name = other.name;
    cargo_volume = other.cargo_volume;
    sizeX = other.sizeX;
    sizeY = other.sizeY;
    sizeZ = other.sizeZ;
    amount_cities = other.amount_cities;
    cities = new std::string[amount_cities];
    for (int i = 0; i < amount_cities; i++) {
        cities[i] = other.cities[i];
    }
}

Plane::~Plane() {
    delete[] cities;
}

Plane &Plane::operator=(const Plane &other) {
    if (this == &other) {
        return *this;
    }

    delete[] cities;

    type = other.type;
    name = other.name;
    cargo_volume = other.cargo_volume;
    sizeX = other.sizeX;
    sizeY = other.sizeY;
    sizeZ = other.sizeZ;
    amount_cities = other.amount_cities;
    cities = new std::string[amount_cities];
    for (int i = 0; i < amount_cities; i++) {
        cities[i] = other.cities[i];
    }

    return *this;
}

void Plane::PrintData() {
    std::cout << "Plane parameters" << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Cargo volume: " << cargo_volume << std::endl;
    std::cout << "Size: " << sizeX << "x" << sizeY << "x" << sizeZ << std::endl;
    std::cout << "Cities: ";
    for (int i = 0; i < amount_cities; i++) {
        std::cout << cities[i];
        if (i != amount_cities - 1) {
            std::cout << ", ";
        } else {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

std::string Plane::GetWriteToFileData() {
    std::string data = type + "|" + name + "|" + std::to_string(cargo_volume) + "|" + std::to_string(sizeX) + "|" +
                       std::to_string(sizeY) + "|" + std::to_string(sizeZ) + "|" + std::to_string(amount_cities) + '|';

    for (int i = 0; i < amount_cities; i++) {
        data += cities[i];
        if (i != amount_cities - 1) {
            data += "#";
        }
    }
    data += Transporter::GetWriteToFileData();
    return data;
}

Transporter *Plane::Clone() const {
    return new Plane(*this);
}

void Plane::setCities(std::string *cities, int amount_cities) {
    delete[] this->cities;
    this->amount_cities = amount_cities;
    this->cities = new std::string[amount_cities];
    for (int i = 0; i < amount_cities; i++) {
        this->cities[i] = cities[i];
    }
}
