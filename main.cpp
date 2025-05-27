#include <iostream>
#include "storage.h"
#include "Ui.h"

int main() {
    Ui u = Ui();
    u.print();
    u.saveData();

    return 0;
}
