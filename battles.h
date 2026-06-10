#pragma once
#include "monsters.h"
#include "menus.h"
#include "player.h"

#include <iostream>

class Battle{
    public:
    Player* player;
    Monster enemy;

    int activeMonster = 0;
    int attackOrder = 0;

    Battle(Player* p);

    void whoStarts();

    void startBattle(Monster monster);

    void playerTurn();
    void monsterTurn();

    void playerAttack();

    void switchMonster();

    bool playerHasLivingMonster();

    void battleOutcome();
    
    void healParty();

    void useItem();

    bool ranAway = false;
    
};
