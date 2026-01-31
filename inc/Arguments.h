#ifndef _ARGUMENTS_H
#define _ARGUMENTS_H

#include <stdint.h>

enum ProgMode
{
    MODE_NONE,
    MODE_CHUNK_CHECK,
};


struct ProgramState
{
    unsigned int mode;
    uint32_t xVal, zVal;
};

struct ProgramState initProgState();
struct ProgramState parseArgv(int, char **);

#endif