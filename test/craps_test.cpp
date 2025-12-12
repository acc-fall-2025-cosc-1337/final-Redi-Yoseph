#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
#include "die.h"

Die::Die() {
    srand(time(0));   // true random each execution
}

int Die::roll() {
    return rand() % sides + 1;
}
TEST_CASE("Verify Roll produces 2–12")
{
    Die die1, die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; i++) {
        roll.roll_dice();
        int value = roll.roll_value();
        REQUIRE(value >= 2);
        REQUIRE(value <= 12);
    }
}
TEST_CASE("Shooter returns valid Roll values")
{
    Die die1, die2;
    Shooter shooter;

    for (int i = 0; i < 10; i++) {
        Roll* r = shooter.throw_dice(die1, die2);
        int value = r->roll_value();
        REQUIRE(value >= 2);
        REQUIRE(value <= 12);
    }
}
TEST_CASE("ComeOutPhase outcomes correct")
{
    ComeOutPhase phase;
    Die d1, d2;

    for (int i = 0; i < 10; i++) {
        Roll* r = new Roll(d1, d2);
        r->roll_dice();
        int v = r->roll_value();

        if (v == 7 || v == 11)
            REQUIRE(phase.get_outcome(r) == RollOutcome::natural);
        else if (v == 2 || v == 3 || v == 12)
            REQUIRE(phase.get_outcome(r) == RollOutcome::craps);
        else
            REQUIRE(phase.get_outcome(r) == RollOutcome::point);

        delete r;
    }
}
TEST_CASE("PointPhase outcomes correct")
{
    Die d1, d2;
    int point = 6;
    PointPhase phase(point);

    for (int i = 0; i < 10; i++) {
        Roll* r = new Roll(d1, d2);
        r->roll_dice();
        int v = r->roll_value();

        if (v == point)
            REQUIRE(phase.get_outcome(r) == RollOutcome::point);
        else if (v == 7)
            REQUIRE(phase.get_outcome(r) == RollOutcome::seven_out);
        else
            REQUIRE(phase.get_outcome(r) == RollOutcome::nopoint);

        delete r;
    }
}
