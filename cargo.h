#ifndef UNTITLED6_CARGO_H
#define UNTITLED6_CARGO_H


#include <string>
#include <vector>
#include <memory>
#include <iostream>


enum class CargoType {
    REGULAR,
    FRAGILE,
    PERISHABLE
};


class Cargo{
private:
    CargoType type = CargoType::REGULAR;
    std::string name;
    float weight;
public:
    Cargo(std::string name, float weight);
    std::string getName();
    float getWeight();
    virtual CargoType getType();
    virtual std::string getText();
    virtual void print();
};

class FragileCargo: public Cargo{
private:
    CargoType type = CargoType::FRAGILE;
    std::string instruction;
public:
    FragileCargo(std::string name, float weight, std::string instruction);
    std::string getInstruction();
    CargoType getType() override;
    std::string getText() override;
    void print() override;
};

class PerishableCargo: public Cargo{
private:
    CargoType type = CargoType::PERISHABLE;
    std::string date;
    void validDate();
public:
    PerishableCargo(std::string name, float weight, std::string instruction);
    CargoType getType() override;
    std::string getText() override;
    void print() override;
};

class CargoFactory{
public:
    static std::shared_ptr<Cargo> createCargo(CargoType type, std::string name, float weight, std::string specialProperty = "");
};

CargoType stringToType(std::string s);
std::string typeToString(CargoType t);



#endif
