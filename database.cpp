#include "database.h"
#include "sqlite3.h"
#include <iostream>


static int getHeroesCallback(
    void* data,
    int argc,
    char** argv,
    char** columnNames)
{
    std::vector<std::string>* heroes =
        static_cast<std::vector<std::string>*>(data);

    if (argc > 0 && argv[0] != nullptr)
    {
        heroes->push_back(argv[0]);
    }

    return 0;
}



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
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS heroes (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT UNIQUE
        );
    )";

    char* errorMessage = nullptr;

    int result = sqlite3_exec(
        db,
        sql,
        nullptr,
        nullptr,
        &errorMessage);

    if (result != SQLITE_OK)
    {
        std::cout
            << "SQL Error: "
            << errorMessage
            << std::endl;

        sqlite3_free(errorMessage);
    }
}


std::vector<std::string> Database::getAllHeroes()
{
    std::vector<std::string> heroes;

    const char* sql =
        "SELECT name FROM heroes;";

    char* errorMessage = nullptr;

    int result = sqlite3_exec(
        db,
        sql,
        getHeroesCallback,
        &heroes,
        &errorMessage);

    if (result != SQLITE_OK)
    {
        std::cout
            << "SQL Error: "
            << errorMessage
            << std::endl;

        sqlite3_free(errorMessage);
    }

    return heroes;
}

void Database::savePlayer(Player& player)
{
    std::string sql =
        "INSERT OR REPLACE INTO heroes(name) VALUES('"
        + player.name +
        "');";

    char* errorMessage = nullptr;

    int result = sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        &errorMessage);
        
    if (result != SQLITE_OK)
    {
        std::cout
            << "SQL Error: "
            << errorMessage
            << std::endl;

        sqlite3_free(errorMessage);
    }
    else
    {
        std::cout
            << "Saved player: "
            << player.name
            << std::endl;
    }
}