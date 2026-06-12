#include "menus.h"
#include "battles.h"
#include "monsters.h"
#include "items.h"
#include "status.h"
#include "caves.h"
#include "database.h"

#include <iostream>

void Menu::mainMenu() {
    int choiceMainMenu = 0;
    std::cout << "Welcome to the Main Menu!" << std::endl;
    std::cout << "1. Start new game" << std::endl;
    std::cout << "2 load game" << std::endl;
    std::cout << "3. Quit" << std::endl;

    std::cin >> choiceMainMenu;

    if (choiceMainMenu == 1) {
        characterChoice();
    }
    else if (choiceMainMenu == 2) {
        loadHero();
    }
    else if (choiceMainMenu == 3) {
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


void Menu::inGameMenu() {
    int choiceInGameMenu = 0;

    std::cout << std::endl;
    std::cout << "===== GAME MENU =====" << std::endl;
    std::cout << "1. Fight a monster" << std::endl;
    std::cout << "2. Enter a cave (3 or more monsters is recommended for caves)" << std::endl;
    std::cout << "3. View your fighters" << std::endl;
    std::cout << "4. View inventory" << std::endl;
    std::cout << "5. Equip monsters with items" << std::endl;
    std::cout << "6. Heal monsters" << std::endl;
    std::cout << "7. Show your stats" << std::endl;
    std::cout << "8. Quit to main menu" << std::endl;

    std::cin >> choiceInGameMenu;

    if (choiceInGameMenu == 1) {
        fightMonster();
    }
    else if (choiceInGameMenu == 2) {
        enterCave();
    }
    else if (choiceInGameMenu == 3) {
        viewFighters();
    }
    else if (choiceInGameMenu == 4) {
        viewInventory();
    }
    else if (choiceInGameMenu == 5){
        giveItemToMonster();
    }
    else if (choiceInGameMenu == 6) {
        healParty();
    }
    else if (choiceInGameMenu == 7) {
        Database db;

        db.open();
        db.printStatistics();
        db.close();
    }

    else if (choiceInGameMenu == 8) {
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
    std::cout << "12. Demon Lord" << std::endl;

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
    else if (choiceFightMonster == 12) {
        battle.startBattle(Monster("demonlord"));
    }

    else {
        std::cout << "Invalid choice." << std::endl;
        fightMonster();
    }

    if (battle.enemy.hp <= 0) {
        if (rand() % 100 == 0) {
            std::vector<std::string> possibleDrops = {
                "bomb",
                "firebomb",
                "thunderbomb",
                "club",
                "fan"
            };
            Database db;

                db.open();

                db.recordMonsterKill(
                    battle.enemy.type,
                    player.name);

                db.close();
            int randomDrop =
                rand() % possibleDrops.size();

            Item reward(possibleDrops[randomDrop]);

            player.inventory.push_back(reward);

            std::cout << "Lucky! The monster dropped a " << reward.name << "!" << std::endl;
        }
        char catchChoice;

        std::cout << "Do you want to catch "
                << battle.enemy.name
                << "? (y/n)" << std::endl;

        std::cin >> catchChoice;

        if (catchChoice == 'y' || catchChoice == 'Y') {
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

            if (!player.party[i].items.empty())
            {
                std::cout << "   Items: ";

                for (int j = 0;
                    j < player.party[i].items.size();
                    j++)
                {
                    std::cout
                        << player.party[i].items[j].name;

                    if (j <
                        player.party[i].items.size() - 1)
                    {
                        std::cout << ", ";
                    }
                }

                std::cout << std::endl;
            }
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
    std::cout << "===== INVENTORY =====" << std::endl;

    if (player.inventory.empty()) {
        std::cout << "Inventory is empty." << std::endl;
    }
    else {
        for (int i = 0; i < player.inventory.size(); i++) {
            std::cout
                << i + 1
                << ". "
                << player.inventory[i].name
                << std::endl;
        }
    }

    int choice;
    std::cin >> choice;

    inGameMenu();
}


void Menu::healParty() {

    for (int i = 0; i < 4; i++) {
        if (player.party[i].name != "")
        {
            player.party[i] =
                Monster(player.party[i].type);
        }
    }

    std::cout << "Your party has been fully healed!" << std::endl;
    inGameMenu();

}

void Menu::giveItemToMonster() {

    if (player.inventory.empty()) {
        std::cout << "You don't have any items!" << std::endl;

        inGameMenu();
        return;
    }

    std::cout << std::endl;
    std::cout << "Choose an item:" << std::endl;

    for (int i = 0; i < player.inventory.size(); i++) {
        std::cout << i + 1 << ". " << player.inventory[i].name << std::endl;
    }

    int itemChoice;
    std::cin >> itemChoice;

    itemChoice--;

    if (itemChoice < 0 ||
        itemChoice >= player.inventory.size()) {
        std::cout << "Invalid choice." << std::endl;

        inGameMenu();
        return;
    }

    std::cout << std::endl;
    std::cout << "Choose a monster:" << std::endl;

    for (int i = 0; i < 4; i++) {
        if (player.party[i].name != "")
        {
            std::cout << i + 1 << ". " << player.party[i].name << std::endl;
        }
    }

    int monsterChoice;
    std::cin >> monsterChoice;

    monsterChoice--;

    if (monsterChoice < 0 ||
        monsterChoice >= 4 ||
        player.party[monsterChoice].name == "") {
        std::cout << "Invalid choice." << std::endl;

        inGameMenu();
        return;
    }

    player.party[monsterChoice].items.push_back(
        player.inventory[itemChoice]
    );

    std::cout << player.inventory[itemChoice].name << " was given to " << player.party[monsterChoice].name << std::endl;

    player.inventory.erase(
        player.inventory.begin() + itemChoice
    );

    inGameMenu();
}

int Menu::getAverageMonsterLevel() {
    int totalLevel = 0;
    int monsterCount = 0;

    for (int i = 0; i < 4; i++) {
        if (player.party[i].name != "") {
            totalLevel += player.party[i].idNumber;
            monsterCount++;
        }
    }

    if (monsterCount == 0) {
        return 1;
    }

    return totalLevel / monsterCount;
}

Monster Menu::getMonsterByLevel(int level) {
    if (level < 1) {
        level = 1;
    }

    if (level > 12) {
        level = 12;
    }

    switch (level)
    {
        case 1:  return Monster("slime");
        case 2:  return Monster("goblin");
        case 3:  return Monster("skeleton");
        case 4:  return Monster("horse");
        case 5:  return Monster("mantis");
        case 6:  return Monster("zombie");
        case 7:  return Monster("orc");
        case 8:  return Monster("knight");
        case 9:  return Monster("giant");
        case 10: return Monster("dragon");
        case 11: return Monster("demon");
        case 12: return Monster("demon Lord");

        default:
            return Monster("slime");
    }
}

void Menu::enterCave()
{
    Cave cave;

    int avg = getAverageMonsterLevel();

    cave.monsters.push_back( getMonsterByLevel(avg - 1));

    cave.monsters.push_back( getMonsterByLevel(avg));

    cave.monsters.push_back(getMonsterByLevel(avg + 1));

    std::vector<std::string> rewards = {
        "bomb",
        "firebomb",
        "thunderbomb",
        "club",
        "fan",
        "curse",
        "poison"
        "legendary spear"
    };

    int randomReward = rand() % rewards.size();

    cave.reward = Item(rewards[randomReward]);

    std::cout << std::endl;
    std::cout << "===== CAVE =====" << std::endl;

    Battle battle(&player);

    for (int i = 0; i < cave.monsters.size(); i++) {
        std::cout << "Monster " << i + 1 << " of " << cave.monsters.size() << std::endl;

        battle.startBattle(
            cave.monsters[i]
        );

        if (!battle.playerHasLivingMonster()) {
            std::cout << "You were defeated!" << std::endl;

            inGameMenu();
            return;
        }
    }

    std::cout << std::endl;
    std::cout << "Cave Cleared!" << std::endl;

    player.inventory.push_back(cave.reward);

    std::cout << "You received " << cave.reward.name << "!" << std::endl;
    inGameMenu();
}

void Menu::loadHero() {
    Database db;

    db.open();

    std::vector<std::string> heroes = db.getAllHeroes();

    if (heroes.empty()) {
        std::cout
            << "No saved heroes found."
            << std::endl;

        db.close();

        mainMenu();
        return;
    }

    std::cout << std::endl;
    std::cout << "===== LOAD HERO =====" << std::endl;

    for (int i = 0; i < heroes.size(); i++) {
        std::cout << i + 1 << ". " << heroes[i] << std::endl;
    }

    int choice;
    std::cin >> choice;

    if (choice < 1 ||
        choice > heroes.size()) {
        std::cout << "Invalid choice." << std::endl;

        db.close();

        mainMenu();
        return;
    }

    player =
        db.loadPlayer(
            heroes[choice - 1]
        );

    db.close();
    std::cout << "Loaded " << player.name << "!" << std::endl;
    inGameMenu();
}