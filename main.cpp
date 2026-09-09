#include <iostream>
#include <string>
#include "Car.h"
#include "Train.h"
#include "Plane.h"

using namespace std;

int main() {
    std::string cities_car2[4]{"London", "Rome", "Tokyo", "New York"};
    float hours_delivery_car2[4]{5.6f, 23.3f, 16.7f, 22.5f};
    float cargo_volumes_car2[4]{94, 250.5, 68.9, 50.8};
    Car car2(2011, "Ferrari", "F430", cities_car2, hours_delivery_car2, cargo_volumes_car2, 4);
    car2.PrintData();

    Plane plane1("Fight", "ABC", 1200, 100, 20, 10, cities_car2, 4);
    std::cout << plane1.GetWriteToFileData();

    return 0;
}
