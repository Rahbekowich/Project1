#include "menus.h"
#include "battles.h"
#include "monsters.h"

#include <iostream>

void Menu::mainMenu() {
    int choiceMainMenu = 0;
    std::cout << "Welcome to the Main Menu!" << std::endl;
    std::cout << "1. Start new game" << std::endl;
    std::cout << "2. Quit" << std::endl;

    std::cin >> choiceMainMenu;

    if (choiceMainMenu == 1) {
        characterChoice();
    }
    else if (choiceMainMenu == 2) {
        std::cout << "Thanks for playing! Goodbye!" << std::endl;
        exit(0);
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        mainMenu();
    }


}

void Menu::characterChoice() {
    std::cout << "Enter your character's name:" << std::endl;
    std::cin >> player.name;

    std::cout << "Welcome " << player.name << "!" << std::endl;

    player.party[0] = Monster("horse");
    player.party[1] = Monster("horse");

    std::cout << "You start with two Horses!" << std::endl;

    inGameMenu();
    

}

void Menu::starterPokemonChoice() {

}

void Menu::inGameMenu() {
    int choiceInGameMenu = 0;

    std::cout << std::endl;
    std::cout << "===== GAME MENU =====" << std::endl;
    std::cout << "1. Fight a monster" << std::endl;
    std::cout << "2. View your fighters" << std::endl;
    std::cout << "3. View inventory" << std::endl;
    std::cout << "4. Quit to main menu" << std::endl;

    std::cin >> choiceInGameMenu;

    if (choiceInGameMenu == 1) {
        fightMonster();
    }
    else if (choiceInGameMenu == 2) {
        viewFighters();
    }
    else if (choiceInGameMenu == 3) {
        viewInventory();
    }
    else if (choiceInGameMenu == 4) {
        mainMenu();
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        inGameMenu();
    }
}

void Menu::fightMonster() {
    int choiceFightMonster = 0;

    std::cout << std::endl;
    std::cout << "Choose a monster to fight:" << std::endl;
    std::cout << "1. Slime" << std::endl;
    std::cout << "2. Goblin" << std::endl;
    std::cout << "3. Skeleton" << std::endl;
    std::cout << "4. Horse" << std::endl;
    std::cout << "5. Mantis" << std::endl;
    std::cout << "6. Zombie" << std::endl;
    std::cout << "7. Orc" << std::endl;
    std::cout << "8. Knight" << std::endl;
    std::cout << "9. Giant" << std::endl;
    std::cout << "10. Dragon" << std::endl;
    std::cout << "11. Demon" << std::endl;

    std::cin >> choiceFightMonster;

    Battle battle(&player);

    if (choiceFightMonster == 1) {
        battle.startBattle(Monster("slime"));
    }
    else if (choiceFightMonster == 2) {
        battle.startBattle(Monster("goblin"));
    }
    else if (choiceFightMonster == 3) {
        battle.startBattle(Monster("skeleton"));
    }
    else if (choiceFightMonster == 4) {
        battle.startBattle(Monster("horse"));
    }
    else if (choiceFightMonster == 5) {
        battle.startBattle(Monster("mantis"));
    }
    else if (choiceFightMonster == 6) {
        battle.startBattle(Monster("zombie"));
    }
    else if (choiceFightMonster == 7) {
        battle.startBattle(Monster("orc"));
    } 
    else if (choiceFightMonster == 8) {
        battle.startBattle(Monster("knight"));
    }
    else if (choiceFightMonster == 9) {
        battle.startBattle(Monster("giant"));
    }
    else if (choiceFightMonster == 10) {
        battle.startBattle(Monster("dragon"));
    }
    else if (choiceFightMonster == 11) {
        battle.startBattle(Monster("demon"));
    }

    else {
        std::cout << "Invalid choice." << std::endl;
    }

    if (battle.enemy.hp <= 0)
    {
        char catchChoice;

        std::cout << "Do you want to catch "
                << battle.enemy.name
                << "? (y/n)" << std::endl;

        std::cin >> catchChoice;

        if (catchChoice == 'y' || catchChoice == 'Y')
        {
            int freeSlot = -1;

            for (int i = 0; i < 4; i++)
            {
                if (player.party[i].name == "")
                {
                    freeSlot = i;
                    break;
                }
            }

            if (freeSlot != -1)
            {
                player.party[freeSlot] = battle.enemy;

                std::cout << battle.enemy.name
                        << " was added to your party!"
                        << std::endl;
            }
            else
            {
                std::cout << "Your party is full." << std::endl;
                std::cout << "Choose a monster to replace:"
                        << std::endl;

                for (int i = 0; i < 4; i++)
                {
                    std::cout
                        << i + 1
                        << ". "
                        << player.party[i].name
                        << std::endl;
                }

                int replaceChoice;
                std::cin >> replaceChoice;

                if (replaceChoice >= 1 &&
                    replaceChoice <= 4)
                {
                    player.party[replaceChoice - 1]
                        = battle.enemy;
                }
            }
        }
    }

    inGameMenu();


}

void Menu::viewFighters() {
    std::cout << std::endl;
    std::cout << "===== YOUR MONSTERS ====="
    << std::endl;


    for (int i = 0; i < 4; i++) {
        if (player.party[i].name == "")
        {
            std::cout
                << i + 1
                << ". Empty slot"
                << std::endl;
        }
        else
        {
            std::cout
                << i + 1
                << ". "
                << player.party[i].name
                << " | HP: "
                << player.party[i].hp
                << " | ATK: "
                << player.party[i].attack
                << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Enter 1 to return."
            << std::endl;

    int choice;
    std::cin >> choice;

    inGameMenu();
}

void Menu::viewInventory() {
    std::cout << std::endl;
    std::cout << "Inventory system not implemented yet."
    << std::endl;


    std::cout << "Enter 1 to return."
            << std::endl;

    int choice;
    std::cin >> choice;

    inGameMenu();
}
