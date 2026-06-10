
#pragma once

#include "monsters.h"

class Menu
{
public:
    Player player;
    void mainMenu();
    void characterChoice();
    void starterPokemonChoice();

    void inGameMenu();
    void fightMonster();

    void viewFighters();
    void viewInventory();

};
