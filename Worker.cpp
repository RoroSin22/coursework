#include "Worker.h"

Worker::Worker(std::string name, std::string surname):
    name(name), surname(surname) {}

void Worker::print() {
    std::cout << name << " " << surname << std::endl;
}


Manager::Manager(std::string name, std::string surname, std::string password):
    Worker(name, surname), password(password){}

