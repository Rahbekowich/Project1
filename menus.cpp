#include "menus.h"
#include "monsters.h"
#include "battles.h"

#include <iostream>



void Menu::mainMenu() {
    int choiceMainMenu = 0;

    std::cout << "Welcome to the Main Menu!" << std::endl;
    std::cout << "Choose your action by entering the according number in your console" << std::endl;
    std::cout << "1. Start new game" << std::endl;
    std::cout << "2. quit" << std::endl;
    
    std::cin >> choiceMainMenu;

    if (choiceMainMenu == 1){
        characterChoice();
    }
    else if (choiceMainMenu == 2){
        std::cout << "Thanks for playing! Goodbye!" << std::endl;
        exit(0);
    }
    else {
        std::cout << "Invalid choice. Please choose either 1 or 2." << std::endl;
    }
};

void Menu::characterChoice(){
    std::string name;
    int choiceStarter = 0;

    std::cout << "Now choose your action!" << std::endl;
    std::cout << "1. Create a new character" << std::endl;
    std::cout << "2. use an existing character" << std::endl;
    std::cin >> choiceStarter;
    if (choiceStarter == 1){
        std::cout << "Enter your character's name: " << std::endl;
        std::cin >> name;
        std::cout << "Your character's name is: " << name << std::endl;
        starterPokemonChoice();
    }
    if (choiceStarter == 2){
        std::cout << "This feature is not implemented yet. Please choose option 1 to create a new character." << std::endl;
    }
    if (choiceStarter != 1 && choiceStarter != 2){
        std::cout << "Invalid choice. Please choose either 1 or 2." << std::endl;
    }
    
};

void Menu::starterPokemonChoice() {
    int choiceStarterPokemon = 0;

    std::cout << "Now choose your starting fighter!" << std::endl;
    std::cout << "1. the horse! A well balanced choice" << std::endl;
    std::cout << "2. the Mantis! A strong but fragile choice" << std::endl;
    std::cout << "3. the zombie! A tanky but weak choice" << std::endl;
    std::cin >> choiceStarterPokemon;

    if (choiceStarterPokemon == 1){
        Monster horse("horse");
        horse.print();
        // Here you would add the horse to the player's inventory or something like that
    }
    if (choiceStarterPokemon == 2){
        Monster mantis("mantis");
        mantis.print();
        // Here you would add the mantis to the player's inventory or something like that
    }
    if (choiceStarterPokemon == 3){
        Monster zombie("zombie");
        zombie.print();
        // Here you would add the zombie to the player's inventory or something like that
    }

    if (choiceStarterPokemon != 1 && choiceStarterPokemon != 2 && choiceStarterPokemon != 3){
        std::cout << "Invalid choice. Please choose either 1, 2 or 3." << std::endl;
    }
};

void Menu::inGameMenu() {
    int choiceInGameMenu = 0;

    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "Choose your action by entering the according number in your console" << std::endl;
    std::cout << "1. fight a monster" << std::endl;
    std::cout << "2. view your fighters" << std::endl;
    std::cout << "3. view your inventory" << std::endl;
    std::cout << "4. quit to main menu" << std::endl;
    std::cin >> choiceInGameMenu;


    if (choiceInGameMenu == 1){
        // Here you would implement the fight a monster functionality
    }
    if (choiceInGameMenu == 2){
        // Here you would implement the view your fighters functionality
    }
    if (choiceInGameMenu == 3){
        // Here you would implement the view your inventory functionality
    }
    if (choiceInGameMenu == 4){
        mainMenu();
    }
    if (choiceInGameMenu != 1 && choiceInGameMenu != 2 && choiceInGameMenu != 3 && choiceInGameMenu != 4){
        std::cout << "Invalid choice. Please choose either 1, 2, 3 or 4." << std::endl;
    }


};

void Menu::fightMonster() {
    int choiceFightMonster = 0;
    std::cout << "You chose to fight a monster!" << std::endl;
    std::cout << "here are the monsters you can fight!" << std::endl;
    std::cout << "1. Slime - The weakest enemy available" << std::endl;
    std::cout << "2. Goblin - A bit stronger than the slime" << std::endl;
    std::cout << "3. Skeleton - A bit stronger than the goblin" << std::endl;
    std::cout << "4. Horse - A well balanced enemy" << std::endl;
    std::cout << "5. Mantis - A strong but fragile enemy " << std::endl;
    std::cout << "6. Zombie - A tanky but weak enemy" << std::endl;
    std::cout << "7. Orc - A strong and tanky enemy" << std::endl;
    std::cout << "8. Knight - A very strong and tanky enemy" << std::endl;
    std::cout << "9. Giant - A very strong and tanky enemy" << std::endl;
    std::cout << "10. Dragon - A very strong and tanky enemy" << std::endl;
    std::cout << "11. Demon - A very strong and tanky enemy" << std::endl;
    std::cout << "12. Demon Lord - The strongest enemy available" << std::endl; 
    std::cin >> choiceFightMonster;


};


void Menu::viewFighters() {
    std::cout << "here are your fighters!" << std::endl;
    std::cout << playerMonster[0].name << " - HP: " << playerMonster[0].hp << " - ATK: " << playerMonster[0].attack << std::endl;
    std::cout << playerMonster[1].name << " - HP: " << playerMonster[1].hp << " - ATK: " << playerMonster[1].attack << std::endl;
    std::cout << playerMonster[2].name << " - HP: " << playerMonster[2] .hp << " - ATK: " << playerMonster[2].attack << std::endl;
    std::cout << playerMonster[3].name << " - HP: " << playerMonster[3] .hp << " - ATK: " << playerMonster[3].attack << std::endl;
    std::endl;
    std::cout << "enter 1 to go back to the in game menu" << std::endl;
    int choiceViewFighters = 0;
    std::cin >> choiceViewFighters;

    for (int i = 0; i < 4; i++){
        if (i == 0){
            if (playerMonster[0].name == ""){
                std::cout << "empty slot" << std::endl;
            }
        }
        if (i == 1){
            if (playerMonster[1].name == ""){
                std::cout << "empty slot" << std::endl;
            }
        }
        if (i == 2){
            if (playerMonster[2].name == ""){
                std::cout << "empty slot" << std::endl;
            }
        }
        if (i == 3){
            if (playerMonster[3].name == ""){
                std::cout << "empty slot" << std::endl;
            }
        }
    }

    if (choiceViewFighters == 1){
        inGameMenu();
    }
};


void Menu::viewInventory() {
    // Here you would implement the view your inventory functionality
};

