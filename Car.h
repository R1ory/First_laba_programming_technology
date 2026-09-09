#pragma once
#include "Transporter.h"
#include <string>
#include <iostream>

class Car : public Transporter {
private:
    int year_release;
    std::string brand;
    std::string model;
    std::string *cities;
    float *hours_delivery;
    float *cargo_volumes;
    int amount_points;

public:
    Car();

    Car(int year_release, const std::string &brand, const std::string &model, const std::string *cities,
        const float *hours_delivery, const float *cargo_volumes, int amount_points);

    Car(const Car &other);

    ~Car() override;

    Car &operator=(const Car &other);

    void PrintData() override;

    std::string GetWriteToFileData() override;
};
