#ifndef _ARGUMENTS_H
#define _ARGUMENTS_H

#include <stdint.h>

enum ProgMode
{
    MODE_NONE,
    MODE_ERROR,
    MODE_CHUNK_CHECK,
    MODE_BOX,
};


struct ProgramState
{
    unsigned int mode, width, height;
    int64_t seed;
    int32_t xVal, zVal, xRange, zRange;
};

/**
 * @brief Initialize a new program state to defaults.
 * 
 * @returns Blank-init program state.
 */
struct ProgramState initProgState();

/**
 * @brief Parse arguments passed in from command line.
 * 
 * @param argc Number of arguments passed in command line.
 * @param argv Array of arguments passed in command line.
 * 
 * @returns Program state indicating operation to perform.
 */
struct ProgramState parseArgv(int, char **);

#endif