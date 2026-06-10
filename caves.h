#pragma once

#include <vector>

#include "monsters.h"
#include "items.h"

class Cave
{
public:
    std::vector<Monster> monsters;

    Item reward;

    Cave();
};