#ifndef RNG_H
#define RNG_H

// A 'wrapper' header file for the pcg rng code

#include "pcg.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef struct Rand {
/**
 * Wrapper struct for pcg32_random_t
 */
	pcg32_random_t* rng;
} Rand;

Rand* new_rand(void) {
 /**
  * Lazily seeds rng with time at seeding and memory address of rng pointer
	* @return rand the seeded rng.
	*/
	Rand* rand = (Rand*)calloc(1, sizeof(Rand)); // allocate memory for struct
	rand->rng = (pcg32_random_t*) calloc(1, sizeof(pcg32_random_t));
	pcg32_srandom_r(rand->rng, time(NULL), (intptr_t)rand);
	return rand;
}

double rand_frac(Rand* rand) {
 /**
  * Generates a random double between (0,1).
	* @param rand a pre-seeded rng that will be used to generate the random double.
	* @return retval the generated random double.
	*/
	double retval = ldexp(pcg32_random_r(rand->rng), -32);
	return retval;
}

int rand_int(Rand* rand, int lower, int upper) {
 /**
  * Generates a random int between [lower, upper).
	* @param rand a pre-seeded rng that will be used to generate the random int.
	* @param lower an int that specifies the lower bound.
	* @param upper an int that specifies the upper bound.
	* @return retval the generated random int.
	*/
	int retval = (int)(rand_frac(rand)*(upper-lower)+lower);
	return retval;
}

double rand_double(Rand* rand, int lower, int upper) {
 /**
  * Generates a random int between [lower, upper).
 	* @param rand a pre-seeded rng that will be used to generate the random int.
 	* @param lower an int that specifies the lower bound.
 	* @param upper an int that specifies the upper bound.
 	* @return retval the generated random double.
 	*/
	int mantissa = rand_int(rand, lower, upper);
	double decimal = rand_frac(rand);
	double retval = mantissa + decimal; // add the mantissa and decimal parts
	return retval;
}

#endif
