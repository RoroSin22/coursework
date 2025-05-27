#ifndef UNTITLED6_WORKER_H
#define UNTITLED6_WORKER_H


#include <string>

class Worker {
private:
    std::string name;
    std::string surname;
public:
    Worker(std::string name, std::string surname);
};

class Manager: Worker {
private:
    std::string password;
public:
    Manager(std::string name, std::string surname, std::string password);
};


#endif
