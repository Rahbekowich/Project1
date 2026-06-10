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
    applyStatuses(enemy);

    if (!canAct(enemy)) {
        return;
    }

    if (enemy.hp <= 0) {
        return;
    }

    std::cout << "The " << enemy.name << " attacks!" << std::endl;

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
    applyStatuses(player->party[activeMonster]);

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
    std::cout << "2. Use item" << std::endl;
    std::cout << "3. Switch monster" << std::endl;
    std::cout << "4. Run away" << std::endl;

    std::cin >> action;

    if (action == 1) {
        playerAttack();
    }
    else if (action == 2) {
        useItem();
    }
    else if (action == 3) {
        switchMonster();
    }
    else if (action == 4) {
        std::cout << "You ran away!" << std::endl;
        ranAway = true;
        return;
    }

    else
    {
        std::cout << "Invalid action. Please choose 1, 2 or 3." << std::endl;
    }

};


void Battle::battleOutcome() {
    if (!playerHasLivingMonster()) {
        std::cout << "All your monsters were defeated!" << std::endl;
        std::cout << "Your party has been healed!" << std::endl;

        for (int i = 0; i < 4; i++)
        {
            if (player->party[i].name != "")
            {
                player->party[i] =
                    Monster(player->party[i].type);
            }
        }
    }
}


void Battle::startBattle(Monster monster) {
    activeMonster = 0;
    enemy = monster;

    std::cout
        << "A wild " << enemy.name << " appears!" << std::endl;

    whoStarts();

while (enemy.hp > 0 && playerHasLivingMonster() && !ranAway) {
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
healParty();

}

void Battle::healParty()
{
    for (int i = 0; i < 4; i++)
    {
        if (player->party[i].name != "")
        {
            player->party[i] =
                Monster(player->party[i].type);
        }
    }
}

void Battle::useItem()
{
    if (player->party[activeMonster].items.empty())
    {
        std::cout << "This monster has no items!" << std::endl;
        return;
    }

    std::cout << "Choose an item:" << std::endl;

    for (int i = 0;
        i < player->party[activeMonster].items.size();
        i++)
    {
        std::cout
            << i + 1
            << ". "
            << player->party[activeMonster].items[i].name
            << std::endl;
    }

    int choice;
    std::cin >> choice;

    choice--;

    if (choice < 0 ||
        choice >= player->party[activeMonster].items.size())
    {
        std::cout << "Invalid choice." << std::endl;
        return;
    }

    Item item =
        player->party[activeMonster].items[choice];

    enemy.hp -= item.damage;
    if (item.statusChance > 0) {
        int roll = rand() % 100;

        if (roll < item.statusChance){

            Status newStatus(item.status, 3);

            enemy.statuses.push_back(newStatus);

            std::cout
                << enemy.name
                << " was afflicted with "
                << newStatus.getName()
                << "!"
                << std::endl;
        }
    }

    if (enemy.hp < 0)
    {
        enemy.hp = 0;
    }

    std::cout
        << item.name
        << " dealt "
        << item.damage
        << " damage!"
        << std::endl;
}

void Battle::applyStatuses(Monster& monster) {
    for (int i = static_cast<int>(monster.statuses.size()) - 1; i >= 0; i--) {
        Status& status = monster.statuses[i];

        if (status.type == Poisoned) {
            monster.hp -= 2;

            std::cout
                << monster.name << " takes 2 poison damage!" << std::endl;

            if (monster.hp < 0) {
                monster.hp = 0;
            }
        }

        status.duration--;
    }

    for (int i = monster.statuses.size() - 1; i >= 0; i--)
    {
        if (monster.statuses[i].duration <= 0)
        {
            monster.statuses.erase(
                monster.statuses.begin() + i
            );
        }
    }
}

bool Battle::canAct(Monster& monster) {
    for (int i = 0; i < monster.statuses.size(); i++)
    {
        if (monster.statuses[i].type == Stunned)
        {
            std::cout
                << monster.name
                << " is stunned and loses its turn!"
                << std::endl;

            return false;
        }

        if (monster.statuses[i].type == Frozen)
        {
            std::cout
                << monster.name
                << " is frozen solid!"
                << std::endl;

            return false;
        }

        if (monster.statuses[i].type == Paralyzed)
        {
            if (rand() % 100 < 30)
            {
                std::cout
                    << monster.name
                    << " is paralyzed and cannot move!"
                    << std::endl;

                return false;
            }
        }
    }

    return true;
}