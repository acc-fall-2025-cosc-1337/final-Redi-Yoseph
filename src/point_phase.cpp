//#include "point_phase.h"

PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll)
{
    int v = roll->roll_value();

    if (v == point) return RollOutcome::point;
    if (v == 7) return RollOutcome::seven_out;

    return RollOutcome::nopoint;
}
