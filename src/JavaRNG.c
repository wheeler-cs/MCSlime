#include "JavaRNG.h"

int64_t setSeed(int64_t seed)
{
    return (seed ^ (uint64_t)0x5deece66d) & (((uint64_t)1 << 48) - 1);
}

int64_t next(int64_t * rngState, unsigned int bits)
{
    *rngState = (*rngState * (uint64_t)0x5deece66d + (uint64_t)0xb) & (((uint64_t)1 << 48) - 1);
    return (uint64_t)(*rngState >> (48 - bits));
}

int64_t nextInt(int64_t * rngState)
{
    return next(rngState, 32);
}

int64_t nextIntBounded(int64_t * rngState, int64_t bound)
{
    if((bound & (-1 * bound)) == bound)
    {
        return (int64_t)((bound * next(rngState, 31)) >> 31);
    }

    int64_t bits, val;
    do
    {
        bits = next(rngState, 31);
        val = bits % bound;
    } while (bits - val + (bound - 1) < 0);
    
    return val;
}
