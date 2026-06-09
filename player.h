#pragma once
#include "monsters.h"
#include "battles.h"
#include "menus.h"



class Player
{
public:
    std::string name;
    Monster party[4];
};