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

void Ui::saveData() {
    nlohmann::json data;
    data["workers"] = nlohmann::json::array();
    for (auto& worker : workerBase){
        nlohmann::json workerData;
        workerData["name"] = worker.getName();
        workerData["surname"] = worker.getSurname();
        data["workers"].push_back(workerData);
    }
    data["managers"] = nlohmann::json::array();
    for (auto& manager : managerBase){
        nlohmann::json managerData;
        managerData["name"] = manager.getName();
        managerData["surname"] = manager.getSurname();
        managerData["password"] = manager.getPassword();
        data["managers"].push_back(managerData);
    }
    std::ofstream("Workers.json") << data.dump(4);
}

void Ui::addWorker(bool status, std::string name, std::string surname, std::string password) {
    if (isManager){
        if (status){
            managerBase.push_back(Manager(name, surname, password));
        } else{
            workerBase.push_back(Worker(name, surname));
        }
    }else{
        std::cerr << "Access denied" << std::endl;
    }
}

void Ui::login() {
    std::string answer;
    std::cout << "Are you a manager?(yes/no)" << std::endl;
    std::cin >> answer;
    std::string enteredName;
    std::cout << "Enter name:" << std::endl;
    std::cin >> enteredName;
    std::string enteredSurname;
    std::cout << "Enter surname:" << std::endl;
    std::cin >> enteredSurname;
    if (answer == "yes"){
        for (auto& manager : managerBase){
            if (manager.getName() == enteredName && manager.getSurname() == enteredSurname){
                std::string password;
                std::cout << "Enter password:" << std::endl;
                std::cin >> password;
                if (manager.getPassword() == password){
                    std::cout << "You are succesfully logged in:" << std::endl;
                    isLogged = true;
                    isManager= true;
                }
                break;
            }
        }
    } else{
        for (auto& worker : workerBase){
            if (worker.getName() == enteredName && worker.getSurname() == enteredSurname){
                std::cout << "You are succesfully logged in:" << std::endl;
                isLogged = true;
                break;
            }
        }
    }
    if (!isLogged){
        std::cerr << "Access denied" << std::endl;
    }

}

Ui::Ui(){
    loadData();
    storage =  Storage::getInstance();
    isLogged = false;
    isManager = false;
}

void Ui::doStuffInStorage(unsigned int command) {
    if (command > 1 && !isManager){
        std::cerr << "Access denied"  << std::endl;
    } else{
        switch (command) {
            case 0: {
                storage->print();
                break;
            }
            case 1:{
                unsigned int places;
                std::cout << "Enter how many places: " << std::endl;
                std::cin >> places;
                storage->addShelf(places);
                break;
            }
            case 2:{
                std::string type;
                std::string name;
                float weight;
                std::string text;
                std::cout << "Enter cargo's name: " << std::endl;
                std::cin >> name;
                std::cout << "Enter type of cargo: " << std::endl;
                std::cin >> type;
                std::cout << "Enter weight of cargo: " << std::endl;
                std::cin >> weight;
                if (stringToType(type) == CargoType::PERISHABLE){
                    std::cout << "Enter date of delay: " << std::endl;
                    std::cin >> text;
                } else if (stringToType(type) == CargoType::FRAGILE){
                    std::cout << "Enter instructions: " << std::endl;
                    std::cin >> text;
                } else{
                    text = "";
                }
                storage->addCargo(stringToType(type), name, weight, text);
                break;
            }
            case 3:{
                std::string cargoName;
                std::cout << "Enter cargo's name: : " << std::endl;
                std::cin >> cargoName;
                storage->removeCargo(cargoName);
                break;
            }
            case 4:{
                std::string answer;
                bool status;
                std::string name;
                std::string surname;
                std::string password;
                std::cout << "Enter workers name : " << std::endl;
                std::cin >> name;
                std::cout << "Enter workers surname: " << std::endl;
                std::cin >> surname;
                std::cout << "Are they a manager?" << std::endl;
                std::cin >> answer;
                if (answer == "yes"){
                    std::cout << "Enter password: " << std::endl;
                    std::cin >> password;
                    status = true;
                } else{
                    password = "";
                    status = false;
                }
                addWorker(status, name, surname, password);
                break;
            }
        }
    }
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