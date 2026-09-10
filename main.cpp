#include <iostream>
#include <string>
#include "Keeper.h"
#include "Car.h"
#include "Plane.h"
#include "Train.h"

using namespace std;

int main() {
    // Keeper keeper1;
    // keeper1.PrintAllObjectsInfo();
    // {
    //     std::string cities_car2[4]{"London", "Rome", "Tokyo", "New York"};
    //     float hours_delivery_car2[4]{5.6f, 23.3f, 16.7f, 22.5f};
    //     float cargo_volumes_car2[4]{94, 250.5, 68.9, 50.8};
    //     Car car2(2011, "Ferrari", "F430", cities_car2, hours_delivery_car2, cargo_volumes_car2, 4);
    //
    //     Train train1("Curs1", 2004, cities_car2, 4, 34, 5000000);
    //     Plane plane1("Fight", "ABC", 1200, 100, 20, 10, cities_car2, 4);
    //
    //     keeper1.PushObject(&train1);
    //     keeper1.PushObject(&plane1);
    //     keeper1.PushObject(&car2);
    // }
    //
    // keeper1.PrintAllObjectsInfo();
    // keeper1.SaveToFile("asdf");

    Keeper keeper2;
    keeper2.ReadFromFile("asdf");
    keeper2.PrintAllObjectsInfo();

    return 0;
}
