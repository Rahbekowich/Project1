#include "menus.h"
#include "database.h"

#include <cstdlib>
#include <ctime>

int main() {
    srand(time(nullptr));

    Database db;

    if (!db.open())
    {
        return 1;
    }

    db.createTables();

    Menu menu;
    menu.mainMenu();

    return 0;
}

