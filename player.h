#pragma once
#include "items.h"

#include "monsters.h"
#include <string>
#include <vector>


class Player {
    public:
    std::string name;

    Monster party[4];
    
    std::vector<item> inventory;

    Player()
    {
        party[0] = Monster();
        party[1] = Monster();
        party[2] = Monster();
        party[3] = Monster();
    }


};
