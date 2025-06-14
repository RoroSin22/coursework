#ifndef UNTITLED6_STORAGE_H
#define UNTITLED6_STORAGE_H


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "json.hpp"
#include "cargo.h"


class Shelf{
private:
    unsigned int maxPlaces;
    unsigned int freePlaces;
    std::vector<std::shared_ptr<Cargo>> cargos;
public:
    Shelf(unsigned int maxPlaces);
    void addCargo(std::shared_ptr<Cargo> cargo);
    void removeCargo(unsigned int cargoId);
    std::shared_ptr<Cargo> getCargo(unsigned int cargoId);
    unsigned int getMaxPlaces();
    unsigned int getFreePlaces();
    void print();
};

class Storage{
private:
    static Storage* instance;
    std::vector<Shelf> shelves;
    void loadData();
    Storage();
    Storage(const Storage&) = delete;
    Storage& operator=(const Storage&) = delete;
    void addShelf(Shelf shelf);

public:
    static Storage* getInstance();
    void print();
    void addShelf(unsigned int places);
    bool addCargo(CargoType type, std::string name, float weight, std::string specialProperty = "");
    bool removeCargo(std::string name);
    void saveData();
};


#endif
