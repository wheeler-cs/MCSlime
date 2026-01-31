#include "Arguments.h"

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
    // Iterate through argv and check arguments
    unsigned int i;
    for(i = 1; i < argc; i++)
    {
        // Check a given chunk for slime status
        if(!(strcmp(argv[i], "-c")))
        {
            state.mode = MODE_CHUNK_CHECK;
        }
    }

    return state;
}
