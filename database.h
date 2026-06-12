#pragma once
#include "player.h"
#include "sqlite3.h"
#include <vector>
#include <string>

class Database {
private:
    sqlite3* db;

    public:
        Database();
        ~Database();

        bool open();
        void close();

        void createTables();

        void savePlayer(Player& player);

        std::vector<std::string> getAllHeroes();

        Player loadPlayer(std::string heroName);

        void recordMonsterKill(
            std::string monster,
            std::string playerName);

        void recordItemUse(
            std::string item,
            std::string playerName);

        void printStatistics();
        

        
};