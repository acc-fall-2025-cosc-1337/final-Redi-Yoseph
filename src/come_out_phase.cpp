#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll)
{
    int v = roll->roll_value();

    if (v == 7 || v == 11) return RollOutcome::natural;
    if (v == 2 || v == 3 || v == 12) return RollOutcome::craps;

    return RollOutcome::point;
}
