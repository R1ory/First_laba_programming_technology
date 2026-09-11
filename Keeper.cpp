#include "Keeper.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Plane.h"
#include "Train.h"
#include "Car.h"

Keeper::Keeper() : Keeper(256) {
}

Keeper::Keeper(int max_amount_transporters) {
    this->max_amount_transporters = max_amount_transporters;
    this->current_amount_transporters = 0;
    transporters = new Transporter *[max_amount_transporters]();
}

Keeper::~Keeper() {
    delete[] transporters;
}

void Keeper::PushObject(const Transporter *transporter) {
    if (current_amount_transporters >= max_amount_transporters) {
        throw std::runtime_error("Keeper overflow! Extend keeper size before add new element.");
    }

    Transporter *new_transporter = transporter->Clone();
    transporters[current_amount_transporters] = new_transporter;
    current_amount_transporters++;
}

void Keeper::RemoveObject(int index) {
    if (index >= current_amount_transporters || index < 0) {
        throw std::runtime_error("Such an element does not exist in container.");
    }
    current_amount_transporters--;
    delete transporters[index];
    for (int i = index; i < current_amount_transporters; i++) {
        transporters[i] = transporters[i + 1];
    }
    transporters[current_amount_transporters] = nullptr;
}

void Keeper::PrintAllObjectsInfo() const {
    std::cout << "Keeper contains: " << std::endl;
    for (int i = 0; i < current_amount_transporters; i++) {
        std::cout << i + 1 << ")" << std::endl;
        transporters[i]->PrintData();
    }
}

void Keeper::SaveToFile(const std::string &file_name) const {
    std::ofstream out(file_name);

    if (out.is_open()) {
        for (int i = 0; i < current_amount_transporters; i++) {
            Plane *planePtr = dynamic_cast<Plane *>(transporters[i]);
            Train *trainPtr = dynamic_cast<Train *>(transporters[i]);
            Car *carPtr = dynamic_cast<Car *>(transporters[i]);
            std::string writeData = planePtr != nullptr ? "Plane|" : trainPtr != nullptr ? "Train|" : "Car|";
            writeData += transporters[i]->GetWriteToFileData();
            out << writeData;
        }
        std::cout << "The data has been successfully written to the file \"" << file_name << "\"" << std::endl;
    } else {
        throw std::runtime_error("The file could not be opened.");
    }

    out.close();
}

void Keeper::ReadFromFile(const std::string &file_name) {
    for (int i = 0; i < current_amount_transporters; i++) {
        delete transporters[i];
    }
    delete[] transporters;
    transporters = new Transporter *[max_amount_transporters];
    current_amount_transporters = 0;

    std::ifstream in(file_name);

    if (in.is_open()) {
        std::string line;
        while (std::getline(in, line)) {
            try {
                std::stringstream ss(line);
                std::string data;
                std::getline(ss, data, '|');
                if (data == "Plane") {
                    Plane *plane = new Plane;

                    std::getline(ss, data, '|');
                    plane->setType(data);

                    std::getline(ss, data, '|');
                    plane->setName(data);

                    std::getline(ss, data, '|');
                    plane->setCargoVolume(std::stof(data));

                    std::getline(ss, data, '|');
                    plane->setSizeX(std::stof(data));

                    std::getline(ss, data, '|');
                    plane->setSizeY(std::stof(data));

                    std::getline(ss, data, '|');
                    plane->setSizeZ(std::stof(data));

                    std::getline(ss, data, '|');
                    int amount_cities = std::stoi(data);
                    std::string *new_cities = new std::string[amount_cities];
                    for (int i = 0; i < amount_cities; i++) {
                        std::getline(ss, data, '#');
                        new_cities[i] = data;
                    }

                    plane->setCities(new_cities, amount_cities);
                    delete[] new_cities;

                    PushObject(plane);
                    delete plane;
                } else if (data == "Train") {
                    Train *train = new Train;

                    std::getline(ss, data, '|');
                    train->setName(data);

                    std::getline(ss, data, '|');
                    train->setYearRelease(std::stoi(data));

                    std::getline(ss, data, '|');
                    train->setAmountBags(std::stoi(data));

                    std::getline(ss, data, '|');
                    train->setCargoVolume(std::stoi(data));

                    std::getline(ss, data, '|');
                    int amount_points = std::stoi(data);
                    std::string *new_path = new std::string[amount_points];
                    for (int i = 0; i < amount_points; i++) {
                        std::getline(ss, data, '#');
                        new_path[i] = data;
                    }
                    train->setPath(new_path, amount_points);
                    delete[] new_path;

                    PushObject(train);

                    delete train;
                } else if (data == "Car") {
                    Car *car = new Car;

                    std::getline(ss, data, '|');
                    car->setYearRelease(std::stoi(data));

                    std::getline(ss, data, '|');
                    car->setBrand(data);

                    std::getline(ss, data, '|');
                    car->setModel(data);

                    std::getline(ss, data, '|');
                    int amount_points = std::stoi(data);
                    std::string *cities = new std::string[amount_points];
                    float *hours_delivery = new float[amount_points];
                    float *cargo_volumes = new float[amount_points];

                    for (int i = 0; i < amount_points; i++) {
                        if (i < amount_points - 1) {
                            std::getline(ss, data, '#');
                        } else {
                            std::getline(ss, data, '|');
                        }
                        cities[i] = data;
                    }

                    for (int i = 0; i < amount_points; i++) {
                        if (i < amount_points - 1) {
                            std::getline(ss, data, '#');
                        } else {
                            std::getline(ss, data, '|');
                        }
                        hours_delivery[i] = std::stof(data);
                    }

                    for (int i = 0; i < amount_points; i++) {
                        std::getline(ss, data, '#');
                        cargo_volumes[i] = std::stof(data);
                    }

                    car->setCities(cities, amount_points);
                    car->setHoursDelivery(hours_delivery, amount_points);
                    car->setCargoVolumes(cargo_volumes, amount_points);

                    delete[] cities;
                    delete[] hours_delivery;
                    delete[] cargo_volumes;

                    PushObject(car);

                    delete car;
                }
            } catch (const std::runtime_error &e) {
                std::cout << "Error catched: " << e.what() << std::endl;
            }
        }
    } else {
        throw std::runtime_error("The file could not be opened.");
    }

    in.close();
}
