#include "cargo.h"


Cargo::Cargo(unsigned int id_, std::string name_, float weight_, std::vector<unsigned int> extra_properties_) {
    id = id_;
    name = name_;
    weight = weight_;
    type = determineType();
    extra_properties = extra_properties_;
}

std::string Cargo::determineType() {
    if (weight < 10.0){
        return "light";
    }
    if (weight > 50.0){
        return "medium";
    }
    return "heavy";

}

unsigned int Cargo::getId() {
    return id;
}

std::string Cargo::getName() {
    return name;
}

std::vector<unsigned int> Cargo::getExtraProperties() {
    return extra_properties;
}

std::string Cargo::getType() {
    return type;
}

float Cargo::getWeight() {
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


