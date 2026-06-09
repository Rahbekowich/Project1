#pragma once
#include "monsters.h"
#include "menus.h"
#include <iostream>


class Battle {
public:
    int attackOrder = 0;       
    Monster playerMonster[4];
    Monster monster;

    int activeMonster = 0;
    
    void switchMonster();
    void startBattle(Monster monster);
    void whoStarts();
    void playerTurn();
    void monsterTurn();
    void playerAttack(Monster monster);
    int battleOutcome();
};                             