#include "storage.h"

Shelf::Shelf(unsigned int maxPlaces):
    maxPlaces(maxPlaces), freePlaces(maxPlaces){}

void Shelf::addCargo(std::shared_ptr<Cargo> cargo) {
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
    if (f.peek() == std::ifstream::traits_type::eof()) {
        data = nlohmann::json{{"storage", nlohmann::json::array()}};
        printf("ERROR JSON");
    } else {
        try {
            f >> data;
            for (const auto& shelfData : data["storage"]["shelves"]) {
                Shelf shelf = Shelf(shelfData["maxPlaces"].get<unsigned int>());
                for (const auto& cargoData : shelfData["cargos"]){
                    shelf.addCargo(CargoFactory::createCargo(stringToType(cargoData["type"].get<std::string>()), cargoData["name"].get<std::string>(), cargoData["weight"].get<float>(), cargoData["text"].get<std::string>()));
                }
                addShelf(shelf);
            }
        } catch (nlohmann::json::parse_error& e) {
            std::cerr << "Error JSON file parsing: " << e.what() <<
                      std::endl;
            data = nlohmann::json{{"storage", nlohmann::json::array()}};
        }
    }
}

void Shelf::print() {
    for(const auto& cargo : cargos){
        cargo->print();
    }
}

void Storage::print() {
    for (Shelf shelf : shelves){
        shelf.print();
    }
}


Storage* Storage::instance = nullptr;