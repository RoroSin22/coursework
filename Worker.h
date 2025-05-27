#ifndef UNTITLED6_WORKER_H
#define UNTITLED6_WORKER_H


#include <string>
#include <iostream>

class Worker {
private:
    std::string name;
    std::string surname;
public:
    Worker(std::string name, std::string surname);
    std::string getName();
    std::string getSurname();
    void print();
};

class Manager: public Worker {
private:
    std::string password;
public:
    Manager(std::string name, std::string surname, std::string password);
    std::string getPassword();
};


#endif
