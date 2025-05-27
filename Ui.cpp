#include "Ui.h"

void Ui::loadData() {
    std::ifstream f("Workers.json");
    nlohmann::json data;
    try {
        f >> data;
        for (const auto& worker : data["workers"]) {
            workerBase.push_back(Worker(worker["name"].get<std::string>(), worker["surname"].get<std::string>()));
        }
        for (const auto& manager : data["managers"]) {
            managerBase.push_back(Manager(manager["name"].get<std::string>(), manager["surname"].get<std::string>(), manager["password"].get<std::string>()));
        }
    } catch (nlohmann::json::parse_error& e) {
        std::cerr << "Error JSON file parsing: " << e.what() << std::endl;
    }
}

Ui::Ui(){
    loadData();
    storage =  Storage::getInstance();
    isLogged = false;
    isManager = false;
}

void Ui::print() {
    storage->print();
    for (auto& i : workerBase){
        i.print();
    }
    for (auto& i : managerBase){
        i.print();
    }
}