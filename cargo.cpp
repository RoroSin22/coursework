#include "cargo.h"


Cargo::Cargo(int id_, float weight_, std::vector<int> extra_properties_) {
    id = id_;
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

int Cargo::getId() {
    return id;
}

std::vector<int> Cargo::getExtraProperties() {
    return extra_properties;
}

std::string Cargo::getType() {
    return type;
}

float Cargo::getWeight() {
    return weight;
}

