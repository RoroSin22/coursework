#include "storage.h"

Shelf::Shelf(unsigned int maxPlaces):
    maxPlaces(maxPlaces), freePlaces(maxPlaces){}

void Shelf::addCargo(std::shared_ptr<Cargo> &cargo) {
    if (freePlaces == 0){
        throw std::invalid_argument("No free places!");
    }
    cargos.push_back(cargo);
    freePlaces--;
}

void Shelf::removeCargo(unsigned int cargoId) {
    if(maxPlaces - freePlaces <= cargoId){
        throw std::invalid_argument("This place is free!");
    }
    cargos.erase(cargos.begin() + cargoId);
}

std::shared_ptr<Cargo> Shelf::getCargo(unsigned int cargoId) {
    if (cargoId < maxPlaces - freePlaces) {
        return cargos[cargoId];
    }
    return nullptr;
}