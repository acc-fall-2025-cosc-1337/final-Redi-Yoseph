#include <iostream>
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main()
{
    srand(time(0));  // REQUIRED

    Die d1, d2;
    Shooter shooter;

    Roll* roll = shooter.throw_dice(d1, d2);
    int rolled_value = roll->roll_value();

    ComeOutPhase come_out;

    // COME OUT PHASE LOOP
    while (come_out.get_outcome(roll) == RollOutcome::natural ||
           come_out.get_outcome(roll) == RollOutcome::craps)
    {
        std::cout << "Rolled " << rolled_value << " roll again\n";
        roll = shooter.throw_dice(d1, d2);
        rolled_value = roll->roll_value();
    }

    // Start of point phase
    std::cout << "Rolled " << rolled_value << " start of point phase\n";
    std::cout << "Roll until " << rolled_value << " or 7 is rolled\n";

    int point = rolled_value;
    roll = shooter.throw_dice(d1, d2);

    PointPhase point_phase(point);

    // POINT PHASE LOOP
    while (point_phase.get_outcome(roll) != RollOutcome::seven_out &&
           point_phase.get_outcome(roll) != RollOutcome::nopoint)
    {
        std::cout << "Rolled " << roll->roll_value() << " roll again\n";
        roll = shooter.throw_dice(d1, d2);
    }

    std::cout << "Rolled " << roll->roll_value() << " end of point phase\n";

    std::cout << "\nAll Rolls:\n";
    shooter.display_rolled_values();
}
