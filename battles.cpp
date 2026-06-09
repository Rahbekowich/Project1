# include "battles.h"
# include "monsters.h"
# include "menus.h"

#include <iostream>

void Battle::whoStarts() {
    int attackOrder = 0;
    int coinFlip = rand() % 2;
    if (coinFlip == 0){
        std::cout << "You start the battle!" << std::endl;
        int attackorder = 1;
    }
    if (coinFlip == 1){
        std::cout << "The " << monster.name << " starts the battle!" << std::endl;
        int attackorder = 2;
    }
}




void Battle::playerTurn() {
    int playerAction = 0;
    std::cout << "Choose your action by entering the according number in your console" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Use an item" << std::endl;
    std::cout << "3. Change monster" << std::endl;
    std::cout << "4. Run away" << std::endl;
    std::cin >> playerAction;

    if (playerAction == 1){
        std::cout << "You attack the " << monster.name << "!" << std::endl;
        int Playerdamage = playerMonster.attack;
        playerAttack(monster);
    }
    if (playerAction == 2){
        // Here you would implement the use an item functionality
    }
    if (playerAction == 3){
        // Here you would implement the run away functionality
    }
    if (playerAction != 1 && playerAction != 2 && playerAction != 3){
        std::cout << "Invalid choice. Please choose either 1, 2 or 3." << std::endl;
    }
}



void monsterTurn() {
    std::cout << "The " << monster.name << " attacks you!" << std::endl;
    int damage = monster.attack;
    int attackMissed = rand() % 10 < 2; // 20% chance to miss
    if (attackMissed) {
        std::cout << "The " << monster.name << "'s attack missed!" << std::endl;
    } 
    else {
        
        // Here you would implement the logic to reduce the player's HP by the damage dealt by the monster
    }
    
};


void Battle::startBattle(Monster monster) {
    std::cout << "A wild " << monster.name << " appears!" << std::endl;
    monster.print();
    whoStarts();
    std::cout << "You got the jump on the " << monster.name << ", and you attack first!" << std::endl;
    if (attackOrder == 1){
        playerTurn();
    }
    std::cout << "The " << monster.name << " got the jump on you, and attacks first!" << std::endl;
    else if (attackOrder == 2){
        monsterTurn();
    }
    // Here you would implement the battle logic, such as player and monster taking turns attacking each other until one of them is defeated
};

void Battle::playerAttack(Monster monster) {
    int damage = playerMonster.attack;


    std::cout << "You dealt " << damage << " damage to the " << monster.name << "!" << std::endl;
        // Here you would implement the logic to reduce the monster's HP by the damage dealt by the player
    

};

int battleOutcome() {
    if (playerMonster.hp <= 0) {
        std::cout << "Your " << playerMonster.name << " was defeated by the " << monster.name << "!" << std::endl;

    }

    else if (monster.hp <= 0) {
        std::cout << "You defeated the " << monster.name << "!" << std::endl;
        // Here you would implement the logic for when the monster is defeated, such as rewarding the player with experience points or items
    }
};
