#include "monsters.h"
#include <map>
#include <iostream>

std::map<std::string, MonsterData> MONSTER_DATA = {
    {"slime",       {"Slime",  8,  2, 1}},
    {"goblin",      {"Goblin", 10, 3, 2}},
    {"skeleton",    {"Skeleton", 12, 4, 3}},
    {"horse",       {"Horse",  15, 5, 4}},
    {"Mantis",      {"Mantis", 12, 7, 5}},
    {"zombie",      {"Zombie",   18, 4, 6}},
    {"orc",         {"Orc",    20, 7, 7}},
    {"knight",      {"Knight",   25, 10, 8}},
    {"giant",       {"Giant",    30, 12, 9}},
    {"dragon",      {"Dragon", 40, 15, 10}},
    {"demon",       {"Demon", 50, 20, 11}},
    {"Demon Lord",  {"Demon Lord", 100, 30, 12}}
};

Monster::Monster(std::string type) {
    MonsterData data = MONSTER_DATA[type];
    name   = data.name;
    hp     = data.hp;
    attack = data.attack;
    idNumber = data.idNumber; // You can set this to a unique value if needed
}

void Monster::print() {
    std::cout << "Monster: " << name 
                << " | HP: " << hp 
                << " | ATK: " << attack << std::endl;
}


