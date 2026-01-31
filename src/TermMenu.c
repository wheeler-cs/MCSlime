#include "TermMenu.h"

#include "TermColors.h"

#include <stdio.h>
#include <string.h>

void mainMenu()
{
    char buff[256],
         command[5][256];
    unsigned int componentQuant;

    // Run program loop
    unsigned int runProg;
    runProg = 1;
    do
    {
        printf("> ");
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
                unsigned int i;
                for(i = 0; i < componentQuant; i++)
                {
                    printf("\n%s", command[i]);
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
            head = tail + 1;
            // Reset temporary string
            for(i = 0; i < 256; i++)
            {
                tempComp[i] = '\0';
            }
        }
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
    printf("\n\n\tmap [x] [z] [w] [h]: Generate a map of slime chunks");
    printf("\n\t\tx: X-axis chunk block to set as origin");
    printf("\n\t\tz: Z-axis chunk block to set as origin");
    printf("\n\t\tw: Width of map to generate");
    printf("\n\t\th: Height of map to generate");
    printf("\n");
}
