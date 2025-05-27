#include "cargo.h"


Cargo::Cargo(unsigned int id, std::string name, std::vector<unsigned int> extra_properties) :
        id(id), name(name), extra_properties(extra_properties) {}


unsigned int Cargo::getId() {
    return id;
}

std::string Cargo::getName() {
    return name;
}

std::vector<unsigned int> Cargo::getExtraProperties() {
    return extra_properties;
}


SmallCargo::SmallCargo(unsigned int id, std::string name, std::vector<unsigned int> extra_properties, float weight, std::string type) :
        Cargo(id, name, extra_properties), weight(weight), type(type) {}

std::string SmallCargo::getType() {
    return type;
}

float SmallCargo::getWeight() {
    return weight;
}

int typeToInt(std::string type){
    if (type == "light"){
        return 1;
    }
    if (type == "medium"){
        return 2;
    }
    if (type == "heavy"){
        return 3;
    }
    return 0;
}

std::string SmallCargo::determineType() {
    if (weight < 10.0){
        return "light";
    }
    if (weight > 50.0){
        return "medium";
    }
    return "heavy";

}

LargeCargo::LargeCargo(unsigned int id, std::string name, std::vector<unsigned int> extra_properties, int size1, int size2) :
        Cargo(id, name, extra_properties) {
    size[0] = size1;
    size[1] = size2;
}

int *LargeCargo::getSize() {
    return size;
}


