#include "storage.h"


Place::Place(unsigned int id_, std::string max_weight_) {
    id = id_;
    max_weight = max_weight_;
    is_taken = false;
    cargo_id = 0;
}

bool Place::addCargo(Cargo cargo) {
    if (is_taken || (typeToInt(max_weight) < typeToInt(cargo.getType()))){
        return false;
    }
    cargo_id = cargo.getId();
    is_taken = true;
    return true;
}

unsigned int Place::getId() {
    return id;
}

std::string Place::getMaxWeight() {
    return max_weight;
}

bool Place::isTaken() {
    return is_taken;
}

unsigned int Place::getCargoId() {
    if (is_taken){
        return cargo_id;
    }
    return 0;
}