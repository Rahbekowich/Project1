#pragma once

#include "items.h"
#include "status.h"

#include <string>
#include <map>
#include <vector>
struct MonsterData {
    std::string name;
    int hp;
    int attack;
    int idNumber; // You can use this to assign a unique ID to each monster if needed
};


extern std::map<std::string, MonsterData> MONSTER_DATA;

class Monster {
public:
    std::string name;
    std::string type;

    int hp;
    int attack;
    int idNumber;

    Monster();
    Monster(std::string type);

    void print();
    
    std::vector<Item> items;
    std::vector<Status> statuses;
};