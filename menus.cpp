#include "menus.h"
#include "monsters.h"

#include <iostream>



void Menu::mainMenu() {
    int choiceMainMenu = 0;

    std::cout << "Welcome to the Main Menu!" << std::endl;
    std::cout << "Choose your action by entering the according number in your console" << std::endl;
    std::cout << "1. Start new game" << std::endl;
    std::cout << "2. quit"
    
    std::cin >> choiceMainMenu;

    if (choiceMainMenu == 1){
        characterChoice
    };
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

void starterPokemonChoice() {
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

};

void Menu::viewInventory() {
    // Here you would implement the view your inventory functionality
};

