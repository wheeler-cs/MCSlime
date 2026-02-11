#include "SlimeChunk.h"

#include "Arguments.h"
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
    // Iterate over range of coordinates
    for(z = 0; z < (int32_t)height; z++)
    {
        for(x = 0; x < (int32_t)width; x++)
        {
            isSlimeChunk = slimeChunk(seed, xPos + x, zPos + z);
            // Print green block for slime chunks
            if(isSlimeChunk)
            {
                setColor(BG_GREEN);
                printf(" ");
            }
            // Print black block for non-slime chunks
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

void linearBoxSearch(int64_t seed, int32_t xOrigin, int32_t zOrigin, int32_t searchWidth, int32_t searchHeight, int boxWidth, int boxHeight)
{
    // Print Search Information
    setDecoration(DECOR_BOLD);
    printf("Search Settings");
    resetTextGraphics();
    printf("\nX-Origin: %d, Z-Origin: %d", xOrigin, zOrigin);
    printf("\nSearch Area: %d-by-%d", searchWidth, searchHeight);
    printf("\nBox Size: %d-by-%d", boxWidth, boxHeight);
    fflush(stdout);
    // Prepare search variables
    int32_t x, z, i, j;
    int grouping, groupsFound;
    groupsFound = 0;
    // Iterate through range of chunks
    for(z = zOrigin; z < zOrigin + searchHeight; z++)
    {
        for(x = xOrigin; x < xOrigin + searchWidth; x++)
        {
            // Slime chunk found, perform check to see if box of chunks is found
            if(slimeChunk(seed, x, z))
            {
                grouping = 1;
                for(i = 0; i < (int32_t)boxWidth && grouping; i++)
                {
                    for(j = 0; j < (int32_t)boxHeight; j++)
                    {
                        // Box of specified size not found
                        if(!slimeChunk(seed, x + i, z + j))
                        {
                            grouping = 0;
                            break;
                        }
                    }
                }
                // Shape was found, print to terminal
                if(grouping)
                {
                    groupsFound++;
                    printf("\nFound grouping at x:%d z:%d", x * 16, z * 16);
                }
            }
        }
    }
    if(!groupsFound)
    {
        printf("\nNo groups found");
    }
    else
    {
        printf("\nFound %d groups", groupsFound);
    }
    printf("\n");
}
