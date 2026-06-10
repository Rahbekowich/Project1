#pragma once
#include "monsters.h"
#include "battles.h"
#include "menus.h"


class Player
{
public:
std::string name;
Monster party[4];

Player(){
    party[0] = Monster();
    party[1] = Monster();
    party[2] = Monster();
    party[3] = Monster();
}

};