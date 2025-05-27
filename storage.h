#ifndef UNTITLED6_STORAGE_H
#define UNTITLED6_STORAGE_H


#include <string>
#include <vector>
#include "cargo.h"

class Shelf{
private:
    unsigned int maxPlaces;
    unsigned int freePlaces;
    std::vector<std::shared_ptr<Cargo>> cargos;
public:
    Shelf(unsigned int maxPlaces);
    void addCargo(std::shared_ptr<Cargo>& cargo);
    void removeCargo(unsigned int cargoId);
    std::shared_ptr<Cargo> getCargo(unsigned int cargoId);
};


#endif
