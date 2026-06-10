#include "database.h"
#include "sqlite3.h"
#include <iostream>

Database::Database() {
    db = nullptr;
}

Database::~Database() {
    close();
}

bool Database::open() {
    int result = sqlite3_open("game.db", &db);

    if (result != SQLITE_OK) {
        std::cout << "Could not open database!" << std::endl;
        return false;
    }

    std::cout << "Database opened!" << std::endl;
    return true;
}

void Database::close() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
    }
}

void Database::createTables()
{
}

