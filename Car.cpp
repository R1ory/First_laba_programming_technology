#include "Car.h"

Car::Car() {
    year_release = 2000;
    brand = "Lada";
    model = "Granta";
    amount_points = 2;
    cities = new std::string[amount_points]{"Moscow", "Paris"};
    hours_delivery = new float[amount_points]{20.4, 17.5};
    cargo_volumes = new float[amount_points]{120, 100};
}

Car::Car(int year_release, const std::string &brand, const std::string &model, const std::string *cities,
         const float *hours_delivery, const float *cargo_volumes, int amount_points) {
    this->year_release = year_release;
    this->brand = brand;
    this->model = model;

    this->amount_points = amount_points;
    this->cities = new std::string[amount_points];
    this->hours_delivery = new float[amount_points];
    this->cargo_volumes = new float[amount_points];
    for (int i = 0; i < amount_points; i++) {
        this->cities[i] = cities[i];
        this->hours_delivery[i] = hours_delivery[i];
        this->cargo_volumes[i] = cargo_volumes[i];
    }
}

Car::Car(const Car &other) {
    year_release = other.year_release;
    brand = other.brand;
    model = other.model;
    amount_points = other.amount_points;
    cities = new std::string[amount_points];
    hours_delivery = new float[amount_points];
    cargo_volumes = new float[amount_points];
    for (int i = 0; i < amount_points; i++) {
        cities[i] = other.cities[i];
        hours_delivery[i] = other.hours_delivery[i];
        cargo_volumes[i] = other.cargo_volumes[i];
    }
}

Car::~Car() {
    delete[] cities;
    delete[] hours_delivery;
    delete[] cargo_volumes;
}

Car &Car::operator=(const Car &other) {
    if (this == &other) {
        return *this;
    }

    delete[] cities;
    delete[] hours_delivery;
    delete[] cargo_volumes;
    year_release = other.year_release;
    brand = other.brand;
    model = other.model;
    amount_points = other.amount_points;
    cities = new std::string[amount_points];
    hours_delivery = new float[amount_points];
    cargo_volumes = new float[amount_points];
    for (int i = 0; i < amount_points; i++) {
        cities[i] = other.cities[i];
        hours_delivery[i] = other.hours_delivery[i];
        cargo_volumes[i] = other.cargo_volumes[i];
    }

    return *this;
}

void Car::PrintData() {
    std::cout << "Car parameters" << std::endl;
    std::cout << "Year of release: " << year_release << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Visit cities: " << std::endl;
    for (int i = 0; i < amount_points; i++) {
        std::cout << "City: " << cities[i] << "\t Delivery hours: " << hours_delivery[i] << "\t Cargo Volume: " <<
                cargo_volumes[i] << std::endl;
    }
    std::cout << std::endl;
}

std::string Car::GetWriteToFileData() {
    std::string data = std::to_string(year_release) + "|" + brand + "|" + model + "|" + std::to_string(amount_points) +
                       "|";
    for (int i = 0; i < amount_points; i++) {
        data += cities[i];
        if (i != amount_points - 1) {
            data += "#";
        } else {
            data += "|";
        }
    }
    for (int i = 0; i < amount_points; i++) {
        data += std::to_string(hours_delivery[i]);
        if (i != amount_points - 1) {
            data += "#";
        } else {
            data += "|";
        }
    }
    for (int i = 0; i < amount_points; i++) {
        data += std::to_string(cargo_volumes[i]);
        if (i != amount_points - 1) {
            data += "#";
        }
    }
    data += Transporter::GetWriteToFileData();
    return data;
}

Transporter *Car::Clone() const {
    return new Car(*this);
}

void Car::setCities(const std::string *cities, int amount_points) {
    delete[] this->cities;
    this->amount_points = amount_points;
    this->cities = new std::string[amount_points];
    for (int i = 0; i < amount_points; i++) {
        this->cities[i] = cities[i];
    }
}

void Car::setHoursDelivery(const float *hours_delivery, int amount_points) {
    delete[] this->hours_delivery;
    this->amount_points = amount_points;
    this->hours_delivery = new float[amount_points];
    for (int i = 0; i < amount_points; i++) {
        this->hours_delivery[i] = hours_delivery[i];
    }
}

void Car::setCargoVolumes(const float *cargo_volumes, int amount_points) {
    delete[] this->cargo_volumes;
    this->amount_points = amount_points;
    this->cargo_volumes = new float[amount_points];
    for (int i = 0; i < amount_points; i++) {
        this->cargo_volumes[i] = cargo_volumes[i];
    }
}
