#pragma once
#include <string>
#include <map>

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
    int hp;
    int attack;
    int idNumber;

    Monster();
    Monster(std::string type);

    void print();
};