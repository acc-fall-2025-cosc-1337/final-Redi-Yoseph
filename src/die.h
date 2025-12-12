//#ifndef DIE_H
#define DIE_H

#include <cstdlib>
#include <ctime>

class Die {
public:
    Die();          // Seed randomness
    int roll();     // Returns 1–6

private:
    int sides{6};
};

#endif
