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
};


#endif
