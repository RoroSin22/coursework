#include "cargo.h"


CargoType stringToType(std::string s){
    if (s == "regular") {
        return CargoType::REGULAR;
    }
    if (s == "fragile") {
        return CargoType::FRAGILE;
    }
    if (s == "perish"){
        return CargoType::PERISHABLE;
    }
    throw std::invalid_argument("Invalid cargo type");
}

std::string typeToString(CargoType t){
    if (t == CargoType::REGULAR) {
        return "regular";
    }
    if (t == CargoType::FRAGILE) {
        return "fragile";
    }
    if (t == CargoType::PERISHABLE){
        return "perish";
    }
    throw std::invalid_argument("Invalid string");
}

Cargo::Cargo(std::string name, float weight):
    name(name), weight(weight) {}

std::string Cargo::getName() {
    return name;
}

CargoType Cargo::getType() {
    return type;
}

CargoType FragileCargo::getType() {
    return type;
}

CargoType PerishableCargo::getType() {
    return type;
}

float Cargo::getWeight() {
    return weight;
}

std::string Cargo::getText() {
    return "";
}

void Cargo::print() {
    std::cout << "      Cargo name: " << name << "\n      Weight: " << weight << std::endl;
}

FragileCargo::FragileCargo(std::string name, float weight, std::string instruction):
    Cargo(name, weight), instruction(instruction) {}

std::string FragileCargo::getInstruction() {
    return instruction;
}

std::string FragileCargo::getText() {
    return instruction;
}

void FragileCargo::print() {
    Cargo::print();
    std::cout << "      Instructions: " << instruction << std::endl;
}


PerishableCargo::PerishableCargo(std::string name, float weight, std::string date):
    Cargo(name, weight), date(date) {
    validDate();
}


std::string PerishableCargo::getText() {
    return date;
}

void PerishableCargo::print() {
    Cargo::print();
    std::cout << "      Date of delay: " << date << std::endl;
}

void PerishableCargo::validDate() {
    if (date.length() < 8){
        throw std::invalid_argument("Invalid date format.");
    }
    if ((!std::isdigit(date[0]) || !std::isdigit(date[1])) || ((date[0]+date[1] - 2 * '0') > 31)){
        throw std::invalid_argument("Invalid day format.");
    }
    if ((!std::isdigit(date[3]) || !std::isdigit(date[4])) || ((date[3]+date[4] - 2 * '0') > 12)){
        throw std::invalid_argument("Invalid month format.");
    }
    if ((!std::isdigit(date[6]) || !std::isdigit(date[7]))){
        throw std::invalid_argument("Invalid year format.");
    }
}

std::shared_ptr<Cargo> CargoFactory::createCargo(CargoType type, std::string name, float weight, std::string specialProperty) {
    switch (type) {
        case CargoType::REGULAR:
            return std::make_shared<Cargo>(name, weight);
        case CargoType::FRAGILE:
            return std::make_shared<FragileCargo>(name, weight, specialProperty);
        case CargoType::PERISHABLE:
            return std::make_shared<PerishableCargo>(name, weight, specialProperty);
        default:
            throw std::invalid_argument("Invalid cargo type");
    }
}


