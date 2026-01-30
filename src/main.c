#include "JavaRNG.h"

#include <stdio.h>

int main(int argc, char ** argv)
{
    uint64_t seed = 11223344,
             rngState,
             val;
    rngState = setSeed(seed);
    val = nextIntBounded(&rngState, 16);

    printf("\n%ld", val);

    return 0;
}
