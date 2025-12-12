//#include "shooter.h"
#include <iostream>

Roll* Shooter::throw_dice(Die& d1, Die& d2) {
    Roll* roll = new Roll(d1, d2);
    roll->roll_dice();
    rolls.push_back(roll);
    return roll;
}

void Shooter::display_rolled_values() {
    for (auto r : rolls) {
        std::cout << r->roll_value() << "\n";
    }
}

Shooter::~Shooter() {
    for (auto r : rolls) {
        delete r;
    }
}
