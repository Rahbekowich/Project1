#include "items.h"

#include <map>

std::map<std::string, ItemData> ITEM_DATA = {
    {"bomb", {"Bomb", 10, 50, Poisoned}},

    {"firebomb", {"Fire Bomb", 5, 50, Stunned}},

    {"thunderbomb", {"Thunder Bomb", 10, 50, Paralyzed}},

    {"club", {"Club", 20, 50, Poisoned}},

    {"fan", {"Fan", 0, 80, Frozen}},

    {"curse", {"Curse", 0, 75, Cursed}},

    {"poison", {"Poison", 0, 50, Poisoned}},

    {"legendary spear", {"Legendary spear Mjolnir", 75, 100, Paralyzed}}
};

Item::Item() {
    name = "";
    damage = 0;
    statusChance = 0;
    status = Poisoned;
}

Item::Item(std::string type) {
    this->type = type;

    ItemData data = ITEM_DATA[type];

    name = data.name;
    damage = data.damage;
    statusChance = data.statusChance;
    status = data.status;
}
