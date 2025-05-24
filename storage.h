#ifndef UNTITLED6_STORAGE_H
#define UNTITLED6_STORAGE_H


#include <string>
#include <vector>
#include "cargo.h"

class Storage {

};

class Place {
private:
    unsigned int id;
    std::string max_weight;
    bool is_taken;
    unsigned int cargo_id;

public:
    Place(unsigned int id_, std::string max_weight_);
    bool addCargo(Cargo cargo);
    unsigned int getId();
    std::string getMaxWeight();
    bool isTaken();
    unsigned int getCargoId();
};


#endif
