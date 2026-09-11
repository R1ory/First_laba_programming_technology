#include "Train.h"

Train::Train() {
    std::cout << "Constructor \"Train\" called" << std::endl;
    name = "Name";
    year_release = 2000;
    amount_points = 2;
    path = new std::string[amount_points]{"Moscow", "Paris"};
    amount_bags = 20;
    cargo_volume = 10000;
}

Train::Train(const std::string &name, int year_release, const std::string *path, int amount_points, int amount_bags,
             float cargo_volume) {
    std::cout << "Constructor \"Train\" called" << std::endl;
    this->name = name;
    this->year_release = year_release;

    this->amount_points = amount_points;
    this->path = new std::string[amount_points];
    for (int i = 0; i < amount_points; i++) {
        this->path[i] = path[i];
    }

    this->amount_bags = amount_bags;
    this->cargo_volume = cargo_volume;
}

Train::Train(const Train &other) {
    std::cout << "Copy constructor \"Train\" called" << std::endl;
    name = other.name;
    year_release = other.year_release;
    amount_points = other.amount_points;
    path = new std::string[amount_points];
    for (int i = 0; i < amount_points; i++) {
        path[i] = other.path[i];
    }

    amount_bags = other.amount_bags;
    cargo_volume = other.cargo_volume;
}

Train::~Train() {
    std::cout << "Destructor \"Train\" called" << std::endl;
    delete[]path;
}

Train &Train::operator=(const Train &other) {
    if (this == &other) {
        return *this;
    }

    delete[] path;

    name = other.name;
    year_release = other.year_release;
    amount_points = other.amount_points;
    path = new std::string[amount_points];
    for (int i = 0; i < amount_points; i++) {
        path[i] = other.path[i];
    }
    amount_bags = other.amount_bags;
    cargo_volume = other.cargo_volume;

    return *this;
}

void Train::PrintData() {
    std::cout << "Train parameters" << std::endl;
    std::cout << "Name train: " << name << std::endl;
    std::cout << "Year of release: " << year_release << std::endl;
    std::cout << "Path: ";
    for (int i = 0; i < amount_points; i++) {
        std::cout << path[i];
        if (i != amount_points - 1) {
            std::cout << " -> ";
        } else {
            std::cout << std::endl;
        }
    }
    std::cout << "Amount bags: " << amount_bags << std::endl;
    std::cout << "Cargo volume: " << cargo_volume << std::endl << std::endl;
}

std::string Train::GetWriteToFileData() {
    std::string data = name + "|" + std::to_string(year_release) + "|" + std::to_string(amount_bags) + "|" +
                       std::to_string(cargo_volume) + "|" + std::to_string(amount_points) + "|";
    for (int i = 0; i < amount_points; i++) {
        data += path[i];
        if (i != amount_points - 1) {
            data += "#";
        }
    }
    data += Transporter::GetWriteToFileData();
    return data;
}

Transporter *Train::Clone() const {
    return new Train(*this);
}

void Train::setPath(const std::string *new_path, int new_amount_points) {
    delete[] path;
    amount_points = new_amount_points;
    path = new std::string[amount_points];
    for (int i = 0; i < amount_points; i++) {
        path[i] = new_path[i];
    }
}
