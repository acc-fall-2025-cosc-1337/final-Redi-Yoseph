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
