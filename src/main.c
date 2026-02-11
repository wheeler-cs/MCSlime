#include "Arguments.h"
#include "SlimeChunk.h"
#include "TermMenu.h"

#include <stdio.h>

int main(int argc, char ** argv)
{
    // Perform automated actions
    if(argc >= 2)
    {
        struct ProgramState pState = parseArgv(argc, argv);
        switch(pState.mode)
        {
            // Check if coordinates are in slime chunk
            case MODE_CHUNK_CHECK:
                break;
            // Perform search for box of slime chunks
            case MODE_BOX:
                linearBoxSearch(pState.seed,
                                pState.xVal,
                                pState.zVal,
                                pState.xRange,
                                pState.zRange,
                                pState.width,
                                pState.height);
                break;
            // Error in argument handling, just exit
            case MODE_ERROR:
            default:
                return 1;
        }
    }
    // Get user input to perform actions
    else
    {
        mainMenu();
    }

    printf("\n");
    return 0;
}
