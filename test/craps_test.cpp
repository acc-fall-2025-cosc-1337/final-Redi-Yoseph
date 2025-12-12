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
