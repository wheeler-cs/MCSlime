#ifndef _SLIME_CHUNK_H
#define _SLIME_CHUNK_H

#include <stdint.h>

/**
 * Slime chunk generation algorithm sourced from:
 * https://minecraft.fandom.com/wiki/Slime#Java_Edition
 */

/**
 * @param seed Seed of world to check.
 * @param xPos Position of chunk along the x-axis.
 * @param zPos Position of chunk along the z-axis.
 * 
 * @returns Boolean value (0 or 1) indicating if chunk is slime chunk or not.
 */
unsigned int slimeChunk(int64_t, int32_t, int32_t);

/**
 * @param seed Seed of world to check.
 * @param xCoord Coordinate along the x-axis inside of chunk to check.
 * @param zCoord Coordinate along the z-axis inside of chunk to check.
 * 
 * @returns Boolean value (0 or 1) indicating if chunk is slime chunk or not.
 */
unsigned int slimeChunkCoords(int64_t, int32_t, int32_t);

/**
 * 
 */
void generateMap(int64_t, int32_t, int32_t, unsigned int, unsigned int);

#endif
