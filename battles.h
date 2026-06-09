#pragma once
#include "monsters.h"
#include "menus.h"
#include <iostream>


class Battle {
public:
    void startBattle(Monster monster);
    void playerAttack(Monster monster);