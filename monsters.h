#pragma once
#include <string>
#include <map>

struct MonsterData {
    std::string name;
    int hp;
    int attack;
};


extern std::map<std::string, MonsterData> MONSTER_DATA;

class Monster {
public:
    std::string name;
    int hp;
    int attack;

    Monster(std::string type);
    void print();

    
};