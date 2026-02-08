#include "SlimeChunk.h"

#include "TermColors.h"
#include "JavaRNG.h"

#include <stdio.h>

unsigned int slimeChunk(int64_t seed, int32_t xPos, int32_t zPos)
{
    int64_t rngSeed = ((seed +
                        (xPos * xPos * 0x4c1906) +
                        (xPos * 0x5ac0db) +
                        (zPos * zPos) * 0x4307a7L +
                        (zPos * 0x5f24f)) ^
                       0x3ad8025fL);
    int64_t rngState = setSeed(rngSeed);
    return (nextIntBounded(&rngState, 10) == 0);
}

unsigned int slimeChunkCoords(int64_t seed, int32_t xCoord, int32_t zCoord)
{
    return slimeChunk(seed, xCoord / 16, zCoord / 16);
}

void generateMap(int64_t seed, int32_t xPos, int32_t zPos, unsigned int width, unsigned int height)
{
    unsigned int isSlimeChunk;
    int32_t x, z;
    for(z = 0; z < (int32_t)height; z++)
    {
        for(x = 0; x < (int32_t)width; x++)
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
