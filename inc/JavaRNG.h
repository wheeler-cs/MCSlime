#ifndef _JAVARNG_H
#define _JAVARNG_H

#include <stdint.h>

/**
 * Java RNG algorithms sourced from Oracle documentation:
 * https://docs.oracle.com/javase/8/docs/api/java/util/Random.htm
 */

/**
 * @param seed Initial seed to use for RNG state.
 * 
 * @returns Newly-initialzed RNG state.
 */
uint64_t setSeed(uint64_t);

/**
 * @param rngState The current RNG state.
 * @param bits The bit size of the value to return.
 * 
 * @returns Random value of a specified width.
 */
uint64_t next(uint64_t *, unsigned int);

/**
 * @param rngState The current RNG state.
 * 
 * @returns A 32-bit pseudorandom integer.
 */
uint64_t nextInt(uint64_t *);

/**
 * @param rngState The current RNG state.
 * @param bound The upper bound to place on the value produced.
 * 
 * @returns A pseudorandom integer between 0 and the bound specified.
 */
uint64_t nextIntBounded(uint64_t *, uint64_t);



#endif
