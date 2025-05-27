#include "Worker.h"

Worker::Worker(std::string name, std::string surname):
    name(name), surname(surname) {}

std::string Worker::getName() {
    return name;
}

std::string Worker::getSurname() {
    return surname;
}

void Worker::print() {
    std::cout << name << " " << surname << std::endl;
}


Manager::Manager(std::string name, std::string surname, std::string password):
    Worker(name, surname), password(password){}

std::string Manager::getPassword() {
    return password;
}