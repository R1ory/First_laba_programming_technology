#include <iostream>
#include <string>
#include "Keeper.h"
#include "Car.h"
#include "Plane.h"
#include "Train.h"

#define MAX_AMOUNT_KEEPERS 256

using namespace std;

int main() {
    Keeper *all_keepers = new Keeper[MAX_AMOUNT_KEEPERS];
    std::string *names_keepers = new std::string[MAX_AMOUNT_KEEPERS];
    int current_amount_keepers = 0;

    while (true) {
        cout << "1. Create new container" << endl;
        cout << "2. Output a list of existing containers" << endl;
        cout << "3. Choose a container for work" << endl;
        cout << "4. Remove Container" << endl;
        cout << "5. Save the container to a file" << endl;
        cout << "6. Read the container from the file" << endl;
        cout << "7. Exit the program" << endl;

        int action_1 = 0;
        cout << endl << "Choose an action:";
        cin >> action_1;
        switch (action_1) {
            case 1: {
                cout << "Enter a name for the new container: ";
                string name_container;
                cin >> name_container;
                Keeper new_keeper;
                all_keepers[current_amount_keepers] = new_keeper;
                names_keepers[current_amount_keepers] = name_container;
                current_amount_keepers++;
                break;
            }
            case 2: {
                for (int i = 0; i < current_amount_keepers; i++) {
                    cout << i + 1 << ". " << names_keepers[i] << endl;
                }
                cout << endl;
                break;
            }
            case 3: {
                int number_container = -1;
                while (number_container < 0 || number_container >= current_amount_keepers) {
                    cout << "Enter the container number: ";
                    cin >> number_container;
                    number_container--;
                }
                while (true) {
                    cout << "1. Add an element to the container" << endl;
                    cout << "2. Output all elements of the container" << endl;
                    cout << "3. Remove an element from the container" << endl;
                    cout << "4. Back" << endl;
                    cout << "Select the action you want to perform on the container: ";
                    int action_2;
                    cin >> action_2;
                    if (action_2 == 4) {
                        break;
                    }
                    switch (action_2) {
                        case 1: {
                            cout << "What element would you like to add?" << endl;
                            cout << "1. Plane" << endl << "2. Train" << endl << "3. Car" << endl;
                            int element_type = -1;
                            while (element_type < 0 || element_type > 3) {
                                cout << "Select the element type: ";
                                cin >> element_type;
                            }
                            switch (element_type) {
                                case 1: {
                                    Plane plane;
                                    std::string enter_string_temp;
                                    float enter_float_temp;

                                    cout << "Enter the plane type: ";
                                    cin >> enter_string_temp;
                                    plane.setType(enter_string_temp);
                                    cout << "Enter the plane name: ";
                                    cin >> enter_string_temp;
                                    plane.setName(enter_string_temp);
                                    cout << "Enter the plane cargo volume: ";
                                    cin >> enter_float_temp;
                                    plane.setCargoVolume(enter_float_temp);
                                    cout << "Enter the plane size X: ";
                                    cin >> enter_float_temp;
                                    plane.setSizeX(enter_float_temp);
                                    cout << "Enter the plane size Y: ";
                                    cin >> enter_float_temp;
                                    plane.setSizeY(enter_float_temp);
                                    cout << "Enter the plane size Z: ";
                                    cin >> enter_float_temp;
                                    plane.setSizeZ(enter_float_temp);

                                    int amount_cities;
                                    cout << "Enter the number of cities: ";
                                    cin >> amount_cities;
                                    if (amount_cities < 0) {
                                        amount_cities = 0;
                                    }
                                    std::string *cities = new std::string[amount_cities];
                                    for (int i = 0; i < amount_cities; i++) {
                                        cout << "Enter the name of the city: ";
                                        cin >> enter_string_temp;
                                        cities[i] = enter_string_temp;
                                    }
                                    plane.setCities(cities, amount_cities);
                                    delete[] cities;

                                    all_keepers[number_container].PushObject(&plane);
                                    break;
                                }
                                case 2: {
                                    Train train;
                                    std::string enter_string_temp;
                                    float enter_float_temp;
                                    int enter_int_temp;

                                    cout << "Enter the train name: ";
                                    cin >> enter_string_temp;
                                    train.setName(enter_string_temp);
                                    cout << "Enter year of release train: ";
                                    cin >> enter_int_temp;
                                    train.setYearRelease(enter_int_temp);
                                    cout << "Enter the number of train bags: ";
                                    cin >> enter_int_temp;
                                    train.setAmountBags(enter_int_temp);
                                    cout << "Enter the train's cargo volume: ";
                                    cin >> enter_float_temp;
                                    train.setCargoVolume(enter_float_temp);

                                    cout << "Enter the number of stop points: ";
                                    cin >> enter_int_temp;
                                    if (enter_int_temp < 0) {
                                        enter_int_temp = 0;
                                    }
                                    std::string *path = new std::string[enter_int_temp];
                                    for (int i = 0; i < enter_int_temp; i++) {
                                        cout << "Enter the name of the stop: ";
                                        cin >> enter_string_temp;
                                        path[i] = enter_string_temp;
                                    }
                                    train.setPath(path, enter_int_temp);
                                    delete[] path;

                                    all_keepers[number_container].PushObject(&train);
                                    break;
                                }
                                case 3: {
                                    Car car;
                                    std::string enter_string_temp;
                                    float enter_float_temp;
                                    int enter_int_temp;

                                    cout << "Enter the year of release car: ";
                                    cin >> enter_int_temp;
                                    car.setYearRelease(enter_int_temp);
                                    cout << "Enter the car brand: ";
                                    cin >> enter_string_temp;
                                    car.setBrand(enter_string_temp);
                                    cout << "Enter the car model: ";
                                    cin >> enter_string_temp;
                                    car.setModel(enter_string_temp);

                                    cout << "Enter the number of destinations: ";
                                    cin >> enter_int_temp;
                                    if (enter_int_temp < 0) {
                                        enter_int_temp = 0;
                                    }
                                    std::string *cities = new std::string[enter_int_temp];
                                    float *cargo_volumes = new float[enter_int_temp];
                                    float *hours_delivery = new float[enter_int_temp];
                                    for (int i = 0; i < enter_int_temp; i++) {
                                        cout << "Enter the name of the destination: ";
                                        cin >> enter_string_temp;
                                        cities[i] = enter_string_temp;
                                        cout << "Enter how many hours until the destination: ";
                                        cin >> enter_float_temp;
                                        hours_delivery[i] = enter_float_temp;
                                        cout << "Enter the cargo volume for the destination: ";
                                        cin >> enter_float_temp;
                                        cargo_volumes[i] = enter_float_temp;
                                    }
                                    car.setCities(cities, enter_int_temp);
                                    car.setHoursDelivery(hours_delivery, enter_int_temp);
                                    car.setCargoVolumes(cargo_volumes, enter_int_temp);
                                    delete[] cities;
                                    delete[] cargo_volumes;
                                    delete[] hours_delivery;

                                    all_keepers[number_container].PushObject(&car);
                                    break;
                                }
                            }
                            break;
                        }
                        case 2: {
                            all_keepers[number_container].PrintAllObjectsInfo();
                            break;
                        }
                        case 3: {
                            int index_element = -1;
                            while (index_element < 0 || index_element >= all_keepers[number_container].
                                   getAmountTransporters()) {
                                cout << "Enter the item number to be removed from the container: ";
                                cin >> index_element;
                                index_element--;
                            }
                            all_keepers[number_container].RemoveObject(index_element);
                            cout << "The element has been successfully removed from container" << endl << endl;
                            break;
                        }
                        default: {
                            cout << "Select an action from the list (1-5)" << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4: {
                int number_container = -1;
                while (number_container < 0 || number_container >= current_amount_keepers) {
                    cout << "Select the container number to be deleted: ";
                    cin >> number_container;
                    number_container--;
                }
                for (int i = number_container; i < number_container - 1; i++) {
                    all_keepers[i] = all_keepers[i + 1];
                }
                current_amount_keepers--;
                cout << "Container has been successfully deleted" << endl << endl;
                break;
            }
            case 5: {
                int number_container = -1;
                while (number_container < 0 || number_container >= current_amount_keepers) {
                    cout << "Select the container number: ";
                    cin >> number_container;
                    number_container--;
                }
                all_keepers[number_container].SaveToFile(names_keepers[number_container]);
                cout << "Container saved to file \"" << names_keepers[number_container] << "\"" << endl << endl;
                break;
            }
            case 6: {
                cout << "Enter the file name: ";
                std::string file_name;
                cin >> file_name;
                Keeper new_keeper;
                new_keeper.ReadFromFile(file_name);
                all_keepers[current_amount_keepers] = new_keeper;
                names_keepers[current_amount_keepers] = file_name;
                current_amount_keepers++;
                cout << "The container has been successfully read and added" << endl << endl;
                break;
            }
            case 7: {
                return 0;
            }
            default: {
                cout << "Select an action from the list (1-7)" << endl << endl;
                break;
            }
        }
    }

    return 0;
}
