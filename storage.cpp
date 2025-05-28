#include "storage.h"

Shelf::Shelf(unsigned int maxPlaces):
    maxPlaces(maxPlaces), freePlaces(maxPlaces){}

void Shelf::addCargo(std::shared_ptr<Cargo> cargo) {
    if (freePlaces == 0){
        std::cerr << "No free places " << std::endl;
    } else {
        cargos.push_back(cargo);
        freePlaces--;
    }
}

void Shelf::removeCargo(unsigned int cargoId) {
    if(maxPlaces - freePlaces <= cargoId){
        std::cerr << "This place is free " << std::endl;
    } else {
        cargos.erase(cargos.begin() + cargoId);
        freePlaces++;
    }
}

unsigned int Shelf::getMaxPlaces() {
    return maxPlaces;
}

unsigned int Shelf::getFreePlaces() {
    return freePlaces;
}

std::shared_ptr<Cargo> Shelf::getCargo(unsigned int cargoId) {
    if (cargoId < maxPlaces - freePlaces) {
        return cargos[cargoId];
    }
    return nullptr;
}

Storage::Storage() {
    loadData();
}

Storage* Storage::getInstance() {
    if (!instance) {
        instance = new Storage();
    }
    return instance;
}

void Storage::addShelf(Shelf shelf) {
    shelves.push_back(shelf);
}

void Storage::loadData() {
    std::ifstream f("Storage.json");
    nlohmann::json data;
    try {
        f >> data;
        for (const auto& shelfData : data["shelves"]) {
            Shelf shelf = Shelf(shelfData["maxPlaces"].get<unsigned int>());
            for (const auto& cargoData : shelfData["cargos"]){
                shelf.addCargo(CargoFactory::createCargo(stringToType(cargoData["type"].get<std::string>()), cargoData["name"].get<std::string>(), cargoData["weight"].get<float>(), cargoData["text"].get<std::string>()));
            }
            addShelf(shelf);
        }
    } catch (nlohmann::json::parse_error& e) {
        std::cerr << "Error JSON file parsing: " << e.what() << std::endl;
    }
}

void Storage::saveData() {
    nlohmann::json storageData;
    storageData["shelves"] = nlohmann::json::array();
    for (auto& shelf : shelves){
        nlohmann::json shelfData;
        shelfData["maxPlaces"] = shelf.getMaxPlaces();
        shelfData["freePlaces"] = shelf.getFreePlaces();
        shelfData["cargos"] = nlohmann::json::array();
        for (unsigned int i = 0; i < shelf.getMaxPlaces() - shelf.getFreePlaces(); i++){
            nlohmann::json cargoData;
            std::shared_ptr<Cargo> cargo = shelf.getCargo(i);
            cargoData["type"] = typeToString(cargo->getType());
            cargoData["name"] = cargo->getName();
            cargoData["weight"] = cargo->getWeight();
            cargoData["text"] = cargo->getText();
            shelfData["cargos"].push_back(cargoData);
        }
        storageData["shelves"].push_back(shelfData);
    }
    std::ofstream("Storage.json") << storageData.dump(4);
}

void Storage::addShelf(unsigned int places) {
    shelves.push_back(Shelf(places));
}

bool Storage::addCargo(CargoType type, std::string name, float weight, std::string specialProperty) {
    for (auto& shelf : shelves){
        if(shelf.getFreePlaces() != 0){
            shelf.addCargo(CargoFactory::createCargo(type, name, weight, specialProperty));
            std::cout << "Cargo was added" << std::endl;
            return true;
        }
    }
    std::cerr << "No free places " << std::endl;
    return false;
}

bool Storage::removeCargo(std::string name) {
    for (auto& shelf : shelves){
        for(unsigned int i = 0; i < shelf.getMaxPlaces() - shelf.getFreePlaces(); i++){
            if (shelf.getCargo(i)->getName() == name){
                shelf.removeCargo(i);
                std::cout << "Cargo was removed" << std::endl;
                return true;
            }
        }
    }
    std::cerr << "There is no such cargo" << std::endl;
    return false;
}

void Shelf::print() {
    for(unsigned int i = 0; i < cargos.size(); i++){
        std::cout << "    Place #" << i << std::endl;
        cargos[i]->print();
    }
}

void Storage::print() {
    for (unsigned int i = 0; i < shelves.size(); i++){
        std::cout << "Shelf #" << i << std::endl;
        std::cout << "Free places = " << shelves[i].getFreePlaces() << " out of " << shelves[i].getMaxPlaces() << std::endl;
        shelves[i].print();
    }
}


Storage* Storage::instance = nullptr;