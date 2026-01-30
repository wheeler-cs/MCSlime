#include "SlimeChunk.h"
#include "JavaRNG.h"

#include <stdio.h>

unsigned int slimeChunk(uint64_t seed, uint32_t xPos, uint32_t zPos)
{
    uint32_t a, b, c, d;
    a = xPos * xPos * 0x4c1906;
    b = xPos * 0x5ac0db;
    c = zPos * zPos * 0x4307a7;
    d = zPos * 0x5f24f;
    uint64_t rngState = setSeed((seed + (uint64_t)a + (uint64_t)b + (uint64_t)c + (uint64_t)d) ^ 0x3ad8025f);
    return (nextIntBounded(&rngState, 10) == 0);
}
