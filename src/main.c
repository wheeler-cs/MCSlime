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
        struct SlimeReport * report;
        struct SearchParameters params;
        switch(pState.mode)
        {
            // Check if coordinates are in slime chunk
            case MODE_CHUNK_CHECK:
                break;
            // Perform search for box of slime chunks
            case MODE_BOX:
                params.seed         = pState.seed;
                params.xOrigin      = pState.xVal;
                params.zOrigin      = pState.zVal;
                params.searchWidth  = pState.xRange;
                params.searchHeight = pState.zRange;
                params.boxWidth     = pState.width;
                params.boxHeight    = pState.height;
                report = linearBoxSearch(params);
                deallocateReport(report);
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
