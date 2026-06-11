#pragma once
#include <iostream>
#include <string>
#include <map>

#include "status.h"

struct ItemData
{
    std::string name;
    int damage;
    int statusChance;
    StatusType status;
};

extern std::map<std::string, ItemData> ITEM_DATA;

class Item {
public:
        std::string type;
        std::string name;

        int damage;
        int statusChance;
        StatusType status;

        Item();
        Item(std::string type);
    };