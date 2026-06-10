#include "monsters.h"
#include <map>
#include <iostream>

std::map<std::string, MonsterData> MONSTER_DATA = {
    {"slime",       {"Slime",  8,  2, 1}},
    {"goblin",      {"Goblin", 10, 3, 2}},
    {"skeleton",    {"Skeleton", 12, 4, 3}},
    {"horse",       {"Horse",  15, 5, 4}},
    {"mantis",      {"Mantis", 12, 7, 5}},
    {"zombie",      {"Zombie",   18, 4, 6}},
    {"orc",         {"Orc",    20, 7, 7}},
    {"knight",      {"Knight",   25, 10, 8}},
    {"giant",       {"Giant",    30, 12, 9}},
    {"dragon",      {"Dragon", 40, 15, 10}},
    {"demon",       {"Demon", 50, 20, 11}},
    {"demon Lord",  {"Demon Lord", 100, 30, 12}}
};

Monster::Monster()
{
    name = "";
    hp = 0;
    attack = 0;
    idNumber = 0;
}

Monster::Monster(std::string type)
{
    this->type = type;

    MonsterData data = MONSTER_DATA[type];

    name = data.name;
    hp = data.hp;
    attack = data.attack;
    idNumber = data.idNumber;
}

void Monster::print() {
    std::cout << "Monster: " << name 
                << " | HP: " << hp 
                << " | ATK: " << attack << std::endl;
}


