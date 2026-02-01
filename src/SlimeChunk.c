#include "SlimeChunk.h"

#include "TermColors.h"
#include "JavaRNG.h"

#include <stdio.h>

unsigned int slimeChunk(int64_t seed, int32_t xPos, int32_t zPos)
{
    uint32_t a, b, c, d;
    a = xPos * xPos * 0x4c1906;
    b = xPos * 0x5ac0db;
    c = zPos * zPos * 0x4307a7;
    d = zPos * 0x5f24f;
    int64_t rngState = setSeed((seed + (int64_t)a + (int64_t)b + (int64_t)c + (int64_t)d) ^ 0x3ad8025f);
    return (nextIntBounded(&rngState, 10) == 0);
}

unsigned int slimeChunkCoords(int64_t seed, int32_t xCoord, int32_t zCoord)
{
    return slimeChunk(seed, xCoord / 16, zCoord / 16);
}

void generateMap(int64_t seed, int32_t xPos, int32_t zPos, unsigned int width, unsigned int height)
{
    unsigned int x, z, isSlimeChunk;
    for(z = 0; z < height; z++)
    {
        for(x = 0; x < width; x++)
        {
            isSlimeChunk = slimeChunk(seed, xPos + x, zPos + z);
            if(isSlimeChunk)
            {
                setColor(BG_GREEN);
                printf(" ");
            }
            else
            {
                setColor(BG_BLACK);
                printf(" ");
            }
            fflush(stdout);
        }
        resetTextGraphics();
        printf("\n");
    }
}
