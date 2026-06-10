#pragma once

#include <string>

enum StatusType {
    Poisoned,
    Frozen,
    Paralyzed,
    Stunned,
    Cursed
};

class Status {
    public:
        StatusType type;
        int duration;

        Status(StatusType type, int duration);

        std::string getName();
};