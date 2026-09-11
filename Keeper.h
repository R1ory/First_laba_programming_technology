#pragma once
#include "Transporter.h"
#include <string>

class Keeper {
private:
    Transporter **transporters;
    int max_amount_transporters;
    int current_amount_transporters;

public:
    Keeper();

    explicit Keeper(int max_amount_transporters);

    ~Keeper();

    int getAmountTransporters() const {
        return current_amount_transporters;
    }


    void PushObject(const Transporter *transporter);

    void RemoveObject(int index);

    void PrintAllObjectsInfo() const;

    void SaveToFile(const std::string &file_name) const;

    void ReadFromFile(const std::string &file_name);
};
