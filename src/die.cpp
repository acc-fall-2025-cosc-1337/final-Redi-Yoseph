#include "die.h"

Die::Die() {
    srand(time(0));   // true random each execution
}

int Die::roll() {
    return rand() % sides + 1;
}
