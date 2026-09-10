#pragma once
#include <string>

class Transporter {
public:
    virtual ~Transporter() = default;


    virtual void PrintData() = 0;

    virtual std::string GetWriteToFileData() = 0;

    [[nodiscard]] virtual Transporter *Clone() const = 0;
};
