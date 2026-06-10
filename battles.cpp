#include "player.h"
#include "battles.h"
#include "menus.h"  
#include "monsters.h"

#include <iostream>

Battle::Battle(Player* p) {
player = p;
}

void Battle::whoStarts() {
attackOrder = rand() % 2 + 1;
    if (attackOrder == 1){
        std::cout << "You start the battle!" << std::endl;
    }
    else{
        std::cout << "The " << enemy.name << " starts the battle!" << std::endl;
    }
}

void Battle::playerAttack() {
    int damage = player->party[activeMonster].attack;
    enemy.hp -= damage;
    std::cout << "You dealt "
            << damage
            << " damage to the "
            << enemy.name
            << "!" << std::endl;

    if (enemy.hp < 0) {
        enemy.hp = 0;
    }

    std::cout << enemy.name
            << " has "
            << enemy.hp
            << " HP left!"
            << std::endl;


}

void Battle::monsterTurn() {
    std::cout << "The "
    << enemy.name
    << " attacks!"
    << std::endl;

    int damage = enemy.attack;

    player->party[activeMonster].hp -= damage;

    if (player->party[activeMonster].hp < 0){
        player->party[activeMonster].hp = 0;
    }

    std::cout << enemy.name
                << " dealt "
                << damage
                << " damage!"
                << std::endl;
};

void Battle::switchMonster() {
    std::cout << "Choose your next monster:" << std::endl;
    for (int i = 0; i < 4; i++){
        if (player->party[i].hp > 0){
            std::cout
                << i + 1
                << ". "
                << player->party[i].name
                << std::endl;
        }
    }

    int choice;
    std::cin >> choice;
    activeMonster = choice - 1;
}

bool Battle::playerHasLivingMonster() {
    for (int i = 0; i < 4; i++) {
        if (player->party[i].hp > 0) {
    return true;
        }
    }
    return false;
}

void Battle::playerTurn() {
    int action;
    std::cout << std::endl;

    std::cout
        << "Your active monster is: "
        << player->party[activeMonster].name
        << " HP: "
        << player->party[activeMonster].hp
        << std::endl;

    std::cout
        << enemy.name
        << " HP: "
        << enemy.hp
        << std::endl;

    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Run away" << std::endl;
    std::cout << "3. Switch monster" << std::endl;

    std::cin >> action;

    if (action == 1)
    {
        playerAttack();
    }
    else if (action == 2)
    {
        enemy.hp = 0;
    }
    else if (action == 3)
    {
        switchMonster();
    }
    else
    {
        std::cout << "Invalid action. Please choose 1, 2 or 3." << std::endl;
    }

};


int Battle::battleOutcome() {
    if (!playerHasLivingMonster())
    {
    std::cout
    << "All your monsters were defeated!"
    << std::endl;

    return 0;
}

if (enemy.hp <= 0)
{
    std::cout
        << "You defeated "
        << enemy.name
        << "!"
        << std::endl;

    return 1;
}

return -1;


}

void Battle::startBattle(Monster monster) {
    enemy = monster;

    std::cout
        << "A wild "
        << enemy.name
        << " appears!"
        << std::endl;

    whoStarts();

while (enemy.hp > 0 && playerHasLivingMonster()) {
    if (attackOrder == 1)
    {
        playerTurn();

        if (enemy.hp <= 0)
        {
            break;
        }

        monsterTurn();
    }
    else
    {
        monsterTurn();

        if (player->party[activeMonster].hp <= 0)
        {
            if (playerHasLivingMonster())
            {
                switchMonster();
            }
            else
            {
                break;
            }
        }

        playerTurn();
    }

    if (player->party[activeMonster].hp <= 0)
    {
        if (playerHasLivingMonster())
        {
            switchMonster();
        }
        else
        {
            break;
        }
    }
}

battleOutcome();

}
