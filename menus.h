#pragma once

#include "player.h"

class Menu {
    public:
    Player player;

    void mainMenu();
    void characterChoice();


    void inGameMenu();
    void fightMonster();

    void viewFighters();
    void viewInventory();
    
    void healParty();

    void giveItemToMonster();

    int getAverageMonsterLevel();
    Monster getMonsterByLevel(int level);
    void enterCave();

    void loadHero();
};
