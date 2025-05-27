#include <iostream>
#include "storage.h"


int main() {
    Storage* s = Storage::getInstance();
    s->print();
s->saveData();

    return 0;
}
