#include <iostream>
#include "storage.h"


int main() {
    Storage* s = Storage::getInstance();
    for (int i = 0; i < 30; i += 10){
        Shelf s2 = Shelf(10);
        for (int j = 0; j < 4; j++){
            s2.addCargo(CargoFactory::createCargo(CargoType::REGULAR, "name", i + j));
        }
        s->addShelf(s2);
    }
    s->print();
    return 0;
}
