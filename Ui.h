#ifndef UNTITLED6_UI_H
#define UNTITLED6_UI_H

#include <vector>
#include "Worker.h"
#include "storage.h"


class Ui {
private:
    std::vector<Worker> workerBase;
    std::vector<Manager> managerBase;
    Storage* storage;
    bool isLogged;
    bool isManager;
public:
    Ui();
    void loadData();
    void print();
    void saveData();
    void login();
    void doStuffInStorage(unsigned int command);
    void addWorker(bool status, std::string name, std::string surname, std::string password = "");
    void mainMenu();
};


#endif
