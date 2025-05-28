#ifndef UNTITLED6_UI_H
#define UNTITLED6_UI_H

#include <vector>
#include "Worker.h"
#include "storage.h"


class WorkerBase{
private:
    std::vector<Worker> workerBase;
    std::vector<Manager> managerBase;
    static WorkerBase* instance;
    WorkerBase(const WorkerBase&) = delete;
    WorkerBase& operator=(const WorkerBase&) = delete;
    WorkerBase();
public:
    static WorkerBase* getInstance();
    void addWorker(bool status, std::string name, std::string surname, std::string password = "");
    void loadData();
    void saveData();
    std::vector<Worker> getWorkers();
    std::vector<Manager> getManagers();
};

class Ui {
private:
    WorkerBase* workerBase;
    Storage* storage;
    bool isLogged;
    bool isManager;
public:
    Ui();
    void saveData();
    void login();
    void allCommands();
    void doStuffInStorage(unsigned int command);
    void addWorker(bool status, std::string name, std::string surname, std::string password);
    void mainMenu();
};


#endif
