#include "TermMenu.h"

#include "SlimeChunk.h"
#include "TermColors.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mainMenu()
{
    char buff[256],
         command[COMMAND_BUFFER_SIZE][256];
    unsigned int componentQuant;

    // Run program loop
    unsigned int runProg;
    runProg = 1;
    do
    {
        printf("\n> ");
        if(fgets(buff, sizeof(buff), stdin) != NULL)
        {
           if(!(strcmp(buff, "exit\n")))
           {
                runProg = 0;
           }
           else if(!(strcmp(buff, "help\n")))
           {
                printHelp();
           }
           else
           {
                parseCommand(buff, command, &componentQuant);
                // Generate a map of chunks using base coordinates
                if(!(strcmp(command[0], "map")))
                {
                    tryGenerateMap(command, componentQuant);
                }
                // Perform a box search for a given seed
                else if(!(strcmp(command[0], "box")))
                {
                    if(componentQuant == 8)
                    {
                        struct SlimeReport * report;
                        struct SearchParameters params;
                        char * end = NULL;
                        params.seed         = (int64_t)strtoll(command[1], &end, 10);
                        params.xOrigin      = (int32_t)atoi(command[2]);
                        params.zOrigin      = (int32_t)atoi(command[3]);
                        params.searchWidth  = (int32_t)atoi(command[4]);
                        params.searchHeight = (int32_t)atoi(command[5]);
                        params.boxWidth     = (int32_t)atoi(command[6]);
                        params.boxHeight    = (int32_t)atoi(command[7]);
                        report = linearBoxSearch(params);
                        deallocateReport(report);
                    }
                }
           }
        }
    } while(runProg);
}

void parseCommand(char * buffer, char parsedCommand[][256], unsigned int * componentQuant)
{
    // Reset component counter
    *componentQuant = 0;
    // Local variables
    char tempComp[256]; // Temporary substring buffer
    unsigned int head, tail, i; // Counter variables
    // Iterate over string and parse based on spaces
    for(head = 0, tail = 1; tail < strlen(buffer); tail++)
    {
        if((buffer[tail] == ' ') || (buffer[tail] == '\n'))
        {
            // Iterate and find command component as substring
            for(i = head; i < tail; i++)
            {
                tempComp[i - head] = buffer[i];
                tempComp[i + 1] = '\0';
            }
            // Copy string and update tracking variables
            strcpy(parsedCommand[*componentQuant], tempComp);
            *componentQuant += 1;
            // Max number of components reached
            if(*componentQuant >= COMMAND_BUFFER_SIZE)
            {
                break;
            }
            head = tail + 1;
            // Reset temporary string
            for(i = 0; i < 256; i++)
            {
                tempComp[i] = '\0';
            }
        }
    }
}

void tryGenerateMap(char components[][256], unsigned int componentQuant)
{
    // Safeguard to make sure correct number of arguments passed in
    if(componentQuant == 6)
    {
        generateMap((int64_t)atoi(components[1]),
                    (int32_t)atoi(components[2]),
                    (int32_t)atoi(components[3]),
                    atoi(components[4]),
                    atoi(components[5]));
    }
    // Print an error message for not enough or too many arguments
    else
    {
        printf("\nIncorrect number of arguments supplied with 'map' command\n");
    }
}

void printHelp()
{
    clearScreen();
    setCursorPosition(0, 0);
    setDecoration(DECOR_BOLD);
    printf("\n\nAvailable Commands:");
    resetTextGraphics();
    // Exit program
    printf("\n\n\texit: Exit program");
    // Map command
    printf("\n\n\tmap [seed] [x] [z] [w] [h]: Generate a map of slime chunks");
    printf("\n\t\tseed: Seed of world");
    printf("\n\t\tx: X-axis chunk block to set as origin");
    printf("\n\t\tz: Z-axis chunk block to set as origin");
    printf("\n\t\tw: Width of map to generate");
    printf("\n\t\th: Height of map to generate");
    printf("\n");
    // Box command
    printf("\n\n\tbox [seed] [ox] [oy] [sw] [sh] [bw] [bh]");
    printf("\n\t\tseed: Seed of world");
    printf("\n\t\tox: X-axis origin chunk block");
    printf("\n\t\toz: Z-axis origin chunk block");
    printf("\n\t\tsw: Width of search");
    printf("\n\t\tsh: Height of search");
    printf("\n\t\tbw: Width of box to find");
    printf("\n\t\tbh: Height of box to find");
    printf("\n");
}

void printProgressBar(unsigned int row, unsigned int column, unsigned int width, double progress)
{
    unsigned int filled, i;
    // Terminal indexing starts at 1, not 0
    if(column < 1)
    {
        column = 1;
    }
    if(row < 1)
    {
        row = 1;
    }
    setCursorPosition(row, column);
    // Print filled portion of bar
    filled = width * progress;
    for(i = 0; i < filled; i++)
    {
        printf("#");
    }
    // Print unfilled portion of bar
    for(i = filled; i < width; i++)
    {
        printf("-");
    }
}
