#include "JavaRNG.h"

uint64_t setSeed(uint64_t seed)
{
    return (seed ^ (uint64_t)0x5deece66d) & (((uint64_t)1 << 48) - 1);
}

uint64_t next(uint64_t * rngState, unsigned int bits)
{
    *rngState = (*rngState * (uint64_t)0x5deece66d + (uint64_t)0xb) & (((uint64_t)1 << 48) - 1);
    return (uint64_t)(*rngState >> (48 - bits));
}

uint64_t nextInt(uint64_t * rngState)
{
    return next(rngState, 32);
}

uint64_t nextIntBounded(uint64_t * rngState, uint64_t bound)
{
    if((bound & (-1 * bound)) == bound)
    {
        return (uint64_t)((bound * next(rngState, 31)) >> 31);
    }

    uint64_t bits, val;
    do
    {
        bits = next(rngState, 31);
        val = bits % bound;
    } while (bits - val + (bound - 1) < 0);
    
    return val;
}
