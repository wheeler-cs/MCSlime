#include "Arguments.h"

#include "TermColors.h"

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
        // Read width parameter of operation
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
        // Read height parameter of operation
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
        else if((!strcmp(argv[i], "-s")) || (!strcmp(argv[i], "--seed")))
        {
            if(argc <= i + 1)
            {
                argError = 1;
                state.mode = MODE_ERROR;
                printf("\nMissing parameter for -s");
            }
            else
            {
                char * end = NULL;
                state.seed = (int64_t)strtoll(argv[i + 1], &end, 10);
            }
        }
        // Print help menu and quit
        else if(!(strcmp(argv[i], "--help")))
        {
            // Print help and make sure program exits
            argError = 1;
            state.mode = MODE_ERROR;
            printArgHelp();
        }
    }

    return state;
}

void printArgHelp(void)
{
    setCursorPosition(1, 1);
    clearScreen();
    setDecoration(DECOR_BOLD);
    printf("\n\nUsage:\nMCSlime [mode] [arguments]");
    resetTextGraphics();
    // Box search
    printf("\n\n\t--box --seed [seed] -x [x origin] -z [z origin] -xr [x radius] -zr [z radius] -w [width] -h [height]");
    printf("\n\t\t--seed: Seed of world to perform check in.");
    printf("\n\t\t-x: Chunk coordinate origin along x-axis for search.");
    printf("\n\t\t-z: Chunk coordinate origin along z-axis for search.");
    printf("\n\t\t-xr: Width of search along the x-axis.");
    printf("\n\t\t-zr: Height of search along the z-axis.");
    printf("\n\t\t-w: Width of box to search for.");
    printf("\n\t\t-h: Height of box to search for.");

    printf("\n");
}
