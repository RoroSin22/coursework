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
    void print();
};

class Storage{
private:
    static Storage* instance;
    nlohmann::json data;
    std::vector<Shelf> shelves;
    void loadData();
    Storage();
    Storage(const Storage&) = delete;
    Storage& operator=(const Storage&) = delete;

public:
    static Storage* getInstance();
    void print();
    void addShelf(Shelf shelf);
};


#endif
