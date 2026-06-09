#include "monsters.h"
#include <map>
#include <iostream>

std::map<std::string, MonsterData> MONSTER_DATA = {
    {"slime",       {"Slime",  8,  2}},
    {"goblin",      {"Goblin", 10, 3}},
    {"skeleton",    {"Skeleton", 12, 4}},
    {"horse",       {"Horse",  15, 5}},
    {"Mantis",      {"Mantis", 12, 7}},
    {"zombie",      {"Zombie",   18, 4}},
    {"orc",         {"Orc",    20, 7}},
    {"knight",      {"Knight",   25, 10}},
    {"giant",       {"Giant",    30, 12}},
    {"dragon",      {"Dragon", 40, 15}},
    {"demon",       {"Demon", 50, 20}},
    {"Demon Lord",  {"Demon Lord", 100, 30}}
};

Monster::Monster(std::string type) {
    MonsterData data = MONSTER_DATA[type];
    name   = data.name;
    hp     = data.hp;
    attack = data.attack;
}

void Monster::print() {
    std::cout << "Monster: " << name 
                << " | HP: " << hp 
                << " | ATK: " << attack << std::endl;
}


