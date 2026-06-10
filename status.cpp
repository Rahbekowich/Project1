#include "status.h"
#include <iostream>


#include "status.h"

Status::Status(StatusType type, int duration) {
    this->type = type;
    this->duration = duration;
}

std::string Status::getName() {
    switch(type){
        case Poisoned:
            return "Poisoned";

        case Frozen:
            return "Frozen";

        case Paralyzed:
            return "Paralyzed";

        case Stunned:
            return "Stunned";

        case Cursed:
            return "Cursed";


        default:
            return "Unknown";
    }
}
