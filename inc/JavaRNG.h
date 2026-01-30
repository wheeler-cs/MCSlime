#ifndef _JAVARNG_H
#define _JAVARNG_H

#include <stdint.h>

/**
 * 
 */
uint64_t setSeed(uint64_t);

/**
 * 
 */
uint64_t next(uint64_t *, unsigned int);

/**
 * 
 */
uint64_t nextInt(uint64_t *);

/**
 * 
 */
uint64_t nextIntBounded(uint64_t *, uint64_t);



#endif
