#include "SlimeChunk.h"

#include <stdio.h>

int main(int argc, char ** argv)
{
    uint64_t seed = -50234;
    unsigned int isSlimeChunk, i, j;
    for(i = 0; i < 8; i ++)
    {
        for(j = 0; j < 8; j++)
        {
            isSlimeChunk = slimeChunk(seed, j, i);
            if(isSlimeChunk)
            {
                printf("O");
            }
            else
            {
                printf("+");
            }
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
