# include "battles.h"
# include "monsters.h"
# include "menus.h"

#include <iostream>

void Battle::whoStarts() {

    int coinFlip = rand() % 2;

    if (coinFlip == 0){
        std::cout << "You start the battle!" << std::endl;
        attackOrder = 1;
    }
    else{
        std::cout << "The " << monster.name << " starts the battle!" << std::endl;
        attackOrder = 2;
    }
}




void Battle::playerTurn() {
    int playerAction = 0;
    std::cout << "Choose your action by entering the according number in your console" << std::endl;
    std::cout << "Your active monster is: " << playerMonster[activeMonster].name << " - HP: " << playerMonster[activeMonster].hp << " - ATK: " << playerMonster[activeMonster].attack << std::endl;
    std::cout << "The enemy " << monster.name << " has " << monster.hp << " HP and " << monster.attack << " ATK" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Use an item" << std::endl;
    std::cout << "3. Change monster" << std::endl;
    std::cout << "4. Run away" << std::endl;
    std::cin >> playerAction;

    if (playerAction == 1){
        std::cout << "You attack the " << monster.name << "!" << std::endl;
        playerAttack(monster);
    }
    if (playerAction == 2){
        std::cout << "this feature is not implemented yet. Please choose another action." << std::endl;
        playerTurn();
    }
    if (playerAction == 3){
        std::cout << "this feature is not implemented yet. Please choose another action." << std::endl;
        playerTurn();
    }
    if (playerAction == 4){
        std::cout << "You run away from the " << monster.name << "!" << std::endl;
        menu::mainMenu();
    }

    if (playerAction != 1 && playerAction != 2 && playerAction != 3 && playerAction != 4){
        std::cout << "Invalid choice. Please choose either 1, 2, 3 or 4." << std::endl;
    }
}



void Battle::monsterTurn() {
    std::cout << "The " << monster.name << " attacks you!" << std::endl;
    int damage = monster.attack;
    int attackMissed = rand() % 10 < 2; // 20% chance to miss
    if (attackMissed) {
        std::cout << "The " << monster.name << "'s attack missed!" << std::endl;
    } 
    else {
        playerMonster[activeMonster].hp -= damage;
        std::cout << "The " << monster.name << " dealt " << damage << " damage to you!" << std::endl;
    }
    
};


void Battle::startBattle(Monster monster) {
    this -> monster = monster;
    std::cout << "A wild " << monster.name << " appears!" << std::endl;
    monster.print();
    whoStarts();
    if (attackOrder == 1){
        std::cout << "You got the jump on the " << monster.name << ", and you attack first!" << std::endl;
        playerTurn();
    }
    else if (attackOrder == 2){
        std::cout << "The " << monster.name << " got the jump on you, and attacks first!" << std::endl;
        monsterTurn();
    }
    // Here you would implement the battle logic, such as player and monster taking turns attacking each other until one of them is defeated
};

void Battle::playerAttack(Monster monster) {
    int damage = playerMonster[activeMonster].attack;


    std::cout << "You dealt " << damage << " damage to the " << monster.name << "!" << std::endl;
    this-> monster.hp -= damage;
    std::cout << "The " << this->monster.name << " has " << this->monster.hp << " HP left!" << std::endl;
};

void Battle::switchMonster() {
    std::cout << "Your " << playerMonster[activeMonster].name << " was defeated!" << std::endl;
    std::cout << "Choose your next monster:" << std::endl;

    for (int i = 0; i < 4; i++) {
        if (playerMonster[i].hp > 0) {
            std::cout << i + 1 << ". " << playerMonster[i].name << std::endl;
        }
    }

    int choice;
    std::cin >> choice;
    activeMonster = choice - 1;  // sæt det aktive monster
}



int Battle::battleOutcome() {
    bool allDead = true;
    for (int i = 0; i < 4; i++) {
        if (playerMonster[i].hp > 0) {
            allDead = false;
            break;
        }
    }

    if (allDead) {
        std::cout << "Your entire party was defeated!" << std::endl;
        std::cout << "You heal your party but the " << monster.name << " gets away!" << std::endl;
        menu::inGameMenu(); // spiller tabte

    } 
    else if (monster.hp <= 0) {
        std::cout << "You defeated the " << monster.name << "!" << std::endl;
        std::cout << "Do you want to catch the " << monster.name << "? (y/n)" << std::endl;
        char catchChoice;
        std::cin >> catchChoice;
        if (catchChoice == 'y' || catchChoice == 'Y' && emptySlotCount > 0) {
            std::cout << "You caught the " << monster.name << "!" << std::endl;
            for (int i = 0; i < 4; i++) {
                if (playerMonster[i].name == "") {
                    playerMonster[i] = monster; 
                    break;
                }
            }
        }   
        else if (catchChoice == 'y' || catchChoice == 'Y' && emptySlotCount == 0) {
            std::cout << "You don't have any empty slots to catch the " << monster.name << "!" << std::endl;
            std::cout << "which monster do you want to switch out?" << std::endl;
            std::cout << "1. " << playerMonster[0].name << std::endl;
            std::cout << "2. " << playerMonster[1].name << std::endl;
            std::cout << "3. " << playerMonster[2].name << std::endl;
            std::cout << "4. " << playerMonster[3].name << std::endl;
            int switchChoice;
            std::cin >> switchChoice;
            playerMonster[switchChoice - 1] = monster;
            menu::inGameMenu();

        }
        if (catchChoice == 'n' || catchChoice == 'N') {
            std::cout << "You chose not to catch the " << monster.name << " and it runs away" << std::endl;
            menu::inGameMenu();
        }

        return 1; // spiller vandt

    } 
    else {
        // Det aktive monster er dødt, men der er andre tilbage
        switchMonster();
        return -1; // kamp fortsætter
    }
};

