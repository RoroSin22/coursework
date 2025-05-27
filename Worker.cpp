#include "Worker.h"

Worker::Worker(std::string name, std::string surname):
    name(name), surname(surname) {}


Manager::Manager(std::string name, std::string surname, std::string password):
    Worker(name, surname), password(password){}

