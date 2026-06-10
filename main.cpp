
#include "menus.h"

#include <cstdlib>
#include <ctime>

int main() {
    srand(time(nullptr));

    Menu menu;
    menu.mainMenu();
    Database db;

    if (!db.open())
    {
        return 1;
    }

    db.createTables();
    return 0;
}
