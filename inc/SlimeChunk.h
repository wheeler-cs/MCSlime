#ifndef _SLIME_CHUNK_H
#define _SLIME_CHUNK_H

#include <stdint.h>

/**
 * Slime chunk generation algorithm sourced from:
 * https://minecraft.fandom.com/wiki/Slime#Java_Edition
 */

/**
 * @brief Calculates if a chunk is a slime chunk using chunk block position.
 * 
 * @param seed Seed of world to check.
 * @param xPos Position of chunk along the x-axis.
 * @param zPos Position of chunk along the z-axis.
 * 
 * @returns Boolean value (0 or 1) indicating if chunk is slime chunk or not.
 */
unsigned int slimeChunk(int64_t, int32_t, int32_t);

/**
 * @brief Checks if a chunk is a slime chunk using player coordinates.
 * 
 * @param seed Seed of world to check.
 * @param xCoord Coordinate along the x-axis inside of chunk to check.
 * @param zCoord Coordinate along the z-axis inside of chunk to check.
 * 
 * @returns Boolean value (0 or 1) indicating if chunk is slime chunk or not.
 */
unsigned int slimeChunkCoords(int64_t, int32_t, int32_t);

/**
 * @brief Generate a map of slime chunks and print it to terminal.
 * 
 * @param seed Seed of world to check.
 * @param xPos Chunk block origin x value to start check at.
 * @param zPos Chunk block origin z value to start check at.
 * @param width Width of map in chunks.
 * @param height Height of map in chunks.
 */
void generateMap(int64_t, int32_t, int32_t, unsigned int, unsigned int);

/**
 * @brief Perform a linear search to find boxes of slime chunks in a given height and width.
 * 
 * @param seed Seed of world to check.
 * @param xOrigin Chunk block origin x value to start check at.
 * @param yOrigin Chunk block origin z valye to start check at.
 * @param searchWidth Width of search in chunks.
 * @param searchHeight Height of search in chunks.
 * @param boxWidth Width of box to search for in chunks.
 * @param boxHeight Height of box to search for in chunks.
 */
void linearBoxSearch(int64_t, int32_t, int32_t, int32_t, int32_t, int, int);

#endif
