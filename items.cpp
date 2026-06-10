#include "items.h"

#include <map>

std::map<std::string, ItemData> ITEM_DATA = {
    {"bomb", {"Bomb", 10, 0, Poisoned}},

    {"firebomb", {"Fire Bomb", 5, 35, Stunned}},

    {"thunderbomb", {"Thunder Bomb", 10, 50, Paralyzed}},

    {"club", {"Club", 20, 0, Poisoned}},

    {"fan", {"Fan", 0, 80, Frozen}},

    {"curse", {"Curse", 0, 20, Cursed}},

    {"poison", {"Poison", 0, 20, Poisoned}},

    {"legendary spear", {"Legendary spear Mjolnir", 75, 100, Paralyzed}}
};

Item::Item() {
    name = "";
    damage = 0;
    statusChance = 0;
    status = Poisoned;
}

Item::Item(std::string type) {
    ItemData data = ITEM_DATA[type];

    name = data.name;
    damage = data.damage;
    statusChance = data.statusChance;
    status = data.status;


}
