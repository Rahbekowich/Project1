#include "database.h"
#include "sqlite3.h"

#include <iostream>
#include <vector>
#include <string>

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

struct LoadPlayerData
{
    Player* player;
};

static int loadPlayerCallback(
    void* data,
    int argc,
    char** argv,
    char** columnNames)
{
    LoadPlayerData* loadData =
        static_cast<LoadPlayerData*>(data);

    int slot =
        std::stoi(argv[0]);

    std::string monsterType =
        argv[1];

    loadData->player->party[slot] =
        Monster(monsterType);

    return 0;
}



Database::Database()
{
    db = nullptr;
}

Database::~Database()
{
    close();
}

bool Database::open()
{
    int result = sqlite3_open("game.db", &db);

    if (result != SQLITE_OK)
    {
        std::cout << "Could not open database!" << std::endl;
        return false;
    }

    std::cout << "Database opened!" << std::endl;
    return true;
}

void Database::close()
{
    if (db != nullptr)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

void Database::createTables()
{
    const char* sqlHeroes = R"(
        CREATE TABLE IF NOT EXISTS heroes (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT UNIQUE
        );
    )";

    const char* sqlParty = R"(
        CREATE TABLE IF NOT EXISTS party_monsters (
            hero_name TEXT,
            slot INTEGER,
            monster_type TEXT
        );
    )";

    const char* sqlInventory = R"(
        CREATE TABLE IF NOT EXISTS inventory (
            hero_name TEXT,
            item_type TEXT
        );
    )";

    const char* sqlMonsterKills = R"(
        CREATE TABLE IF NOT EXISTS monster_kills (
            player_name TEXT,
            monster_type TEXT
        );
    )";

    const char* sqlItemUses = R"(
        CREATE TABLE IF NOT EXISTS item_uses (
            player_name TEXT,
            item_name TEXT
        );
    )";

    char* errorMessage = nullptr;

    sqlite3_exec(db, sqlHeroes, nullptr, nullptr, &errorMessage);
    sqlite3_exec(db, sqlParty, nullptr, nullptr, &errorMessage);
    sqlite3_exec(db, sqlInventory, nullptr, nullptr, &errorMessage);
    sqlite3_exec(db, sqlMonsterKills, nullptr, nullptr, &errorMessage);
    sqlite3_exec(db, sqlItemUses, nullptr, nullptr, &errorMessage);
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

void Database::savePlayer(Player& player) {
    std::string heroSql =
        "INSERT OR REPLACE INTO heroes(name) VALUES('"
        + player.name +
        "');";

    sqlite3_exec(
        db,
        heroSql.c_str(),
        nullptr,
        nullptr,
        nullptr);

    std::string deleteParty =
        "DELETE FROM party_monsters WHERE hero_name='"
        + player.name +
        "';";

    sqlite3_exec(
        db,
        deleteParty.c_str(),
        nullptr,
        nullptr,
        nullptr);

    for (int i = 0; i < 4; i++)
    {
        if (player.party[i].name != "")
        {
            std::string monsterSql =
                "INSERT INTO party_monsters "
                "(hero_name, slot, monster_type) "
                "VALUES('"
                + player.name
                + "', "
                + std::to_string(i)
                + ", '"
                + player.party[i].type
                + "');";

            sqlite3_exec(
                db,
                monsterSql.c_str(),
                nullptr,
                nullptr,
                nullptr);
        }
    }

    std::string deleteInventory =
        "DELETE FROM inventory WHERE hero_name='"
        + player.name +
        "';";

    sqlite3_exec(
        db,
        deleteInventory.c_str(),
        nullptr,
        nullptr,
        nullptr);

    for (Item item : player.inventory)
    {
        std::string inventorySql =
            "INSERT INTO inventory "
            "(hero_name, item_type) "
            "VALUES('"
            + player.name
            + "', '"
            + item.type
            + "');";

        sqlite3_exec(
            db,
            inventorySql.c_str(),
            nullptr,
            nullptr,
            nullptr);
    }

    std::cout
        << "Saved player: "
        << player.name
        << std::endl;
}
Player Database::loadPlayer(std::string heroName)
{
    Player player;

    player.name = heroName;

    std::string sql =
        "SELECT slot, monster_type "
        "FROM party_monsters "
        "WHERE hero_name='"
        + heroName +
        "';";

    LoadPlayerData data;
    data.player = &player;

    sqlite3_exec(
        db,
        sql.c_str(),
        loadPlayerCallback,
        &data,
        nullptr);

    return player;
}

void Database::recordMonsterKill(
    std::string monster,
    std::string playerName)
{
    std::string sql =
        "INSERT INTO monster_kills "
        "(player_name, monster_type) "
        "VALUES('"
        + playerName
        + "', '"
        + monster
        + "');";

    sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        nullptr);
}

void Database::recordItemUse(
    std::string item,
    std::string playerName)
{
    std::string sql =
        "INSERT INTO item_uses "
        "(player_name, item_name) "
        "VALUES('"
        + playerName
        + "', '"
        + item
        + "');";

    sqlite3_exec(
        db,
        sql.c_str(),
        nullptr,
        nullptr,
        nullptr);
}