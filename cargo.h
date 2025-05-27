#ifndef UNTITLED6_CARGO_H
#define UNTITLED6_CARGO_H


#include <string>
#include <vector>
#include <memory>


enum class CargoType {
    REGULAR,
    FRAGILE,
    PERISHABLE
};


class Cargo{
private:
    std::string name;
    float weight;
public:
    Cargo(std::string name, float weight);
    std::string getName();
    float getWeight();
};

class FragileCargo: public Cargo{
private:
    std::string instruction;
public:
    FragileCargo(std::string name, float weight, std::string instruction);
    std::string getInstruction();
};

class PerishableCargo: public Cargo{
private:
    std::string date;
    void validDate();
public:
    PerishableCargo(std::string name, float weight, std::string instruction);
    std::string getDate();
};

class CargoFactory{
public:
    static std::shared_ptr<Cargo> createCargo(CargoType type, std::string name, float weight, std::string specialProperty = "");
};




#endif
