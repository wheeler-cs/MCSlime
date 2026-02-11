#include "Arguments.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ProgramState initProgState()
{
    struct ProgramState state;

    // Init program state to defaults
    state.mode = MODE_NONE;

    return state;
}

struct ProgramState parseArgv(int argc, char ** argv)
{
    struct ProgramState state;
    int argError;
    // Iterate through argv and check arguments
    int i;
    argError = 0;
    for(i = 1; (i < argc) && (!argError); i++)
    {
        // Check a given chunk for slime status
        if(!(strcmp(argv[i], "-c")) || !(strcmp(argv[i], "--check")))
        {
            state.mode = MODE_CHUNK_CHECK;
        }
        // Search for a box of chunks
        else if(!(strcmp(argv[i], "-b")) || !(strcmp(argv[i], "--box")))
        {
            state.mode = MODE_BOX;
        }
        // Read in parameter for x
        else if(!(strcmp(argv[i], "-x")))
        {
            if(argc <= i + 1)
            {
                argError = 1;
                state.mode = MODE_ERROR;
                printf("\nMissing parameter for -x");
            }
            else
            {
                state.xVal = (int32_t)atoi(argv[i + 1]);
            }
        }
        // Read in parameter for y
        else if(!(strcmp(argv[i], "-z")))
        {
            if(argc <= i + 1)
            {
                argError = 1;
                state.mode = MODE_ERROR;
                printf("\nMissing parameter for -z");
            }
            else
            {
                state.zVal = (int32_t)atoi(argv[i + 1]);
            }
        }
        // Get x-axis range of operation
        else if(!(strcmp(argv[i], "-xr")))
        {
            if(argc <= i + 1)
            {
                argError = 1;
                state.mode = MODE_ERROR;
                printf("\nMissing parameter for -xr");
            }
            else
            {
                state.xRange = (int32_t)atoi(argv[i + 1]);
            }
        }
        // Get z-axis range of operation
        else if(!(strcmp(argv[i], "-zr")))
        {
            if(argc <= i + 1)
            {
                argError = 1;
                state.mode = MODE_ERROR;
                printf("\nMissing parameter for -zr");
            }
            else
            {
                state.zRange = (int32_t)atoi(argv[i + 1]);
            }
        }
        else if(!(strcmp(argv[i], "-w")))
        {
            if(argc <= i + 1)
            {
                argError = 1;
                state.mode = MODE_ERROR;
                printf("\nMissing parameter for -w");
            }
            else
            {
                state.width = (int32_t)atoi(argv[i + 1]);
            }
        }
        else if(!(strcmp(argv[i], "-h")))
        {
            if(argc <= i + 1)
            {
                argError = 1;
                state.mode = MODE_ERROR;
                printf("\nMissing parameter for -h");
            }
            else
            {
                state.height = (int32_t)atoi(argv[i + 1]);
            }
        }
        // Read in parameter for seed
        else if(!(strcmp(argv[i], "-s")))
        {
            if(argc <= i + 1)
            {
                argError = 1;
                state.mode = MODE_ERROR;
                printf("\nMissing parameter for -s");
            }
            else
            {
                state.seed = (int64_t)atoi(argv[i + 1]);
            }
        }
    }

    return state;
}
