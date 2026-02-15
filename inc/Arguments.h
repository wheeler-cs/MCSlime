#ifndef _ARGUMENTS_H
#define _ARGUMENTS_H

#include <stdint.h>

/**
 * @brief Indicates mode of operation specified in arguments.
 */
enum ProgMode
{
    MODE_NONE,          ///< Nothing was specified (default value)
    MODE_ERROR,         ///< Error occurred during argument parsing
    MODE_CHUNK_CHECK,   ///< Perform a single chunk check
    MODE_BOX,           ///< Perform a linear box search
};


/**
 * @brief Holds state information of program to be used in operations.
 */
struct ProgramState
{
    unsigned int mode,      //< Mode of operation to be completed.
                 width,     //< Width variable for corresponding operation.
                 height;    //< Height variable for corresponding operation.
    int64_t seed;           //< World seed to use for generation tasks.
    int32_t xVal,           //< X-axis origin value for operation.
            zVal,           //< Z-axis origin value for operation.
            xRange,         //< Range along x-axis for operation.
            zRange;         //< Range along z-axis for operation
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

/**
 * @brief Print help message to terminal describing potential arguments.
 */
void printArgHelp(void);

#endif