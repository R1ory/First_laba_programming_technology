#pragma once
#include "Transporter.h"
#include <string>
#include <iostream>

class Train : public Transporter {
private:
    std::string name;
    int year_release;
    std::string *path;
    int amount_points;
    int amount_bags;
    float cargo_volume;

public:
    Train();

    Train(const std::string &name, int year_release, const std::string *path, int amount_points, int amount_bags,
          float cargo_volume);

    Train(const Train &other);

    ~Train() override;

    Train &operator=(const Train &other);


    void PrintData() override;

    std::string GetWriteToFileData() override;

    [[nodiscard]] Transporter *Clone() const override;


    void setName(const std::string &new_name) { name = new_name; }
    void setYearRelease(int new_year_release) { year_release = new_year_release; }
    void setAmountBags(int new_amount_bags) { amount_bags = new_amount_bags; }
    void setCargoVolume(float new_cargo_volume) { cargo_volume = new_cargo_volume; }

    void setPath(const std::string *new_path, int new_amount_points);
};
