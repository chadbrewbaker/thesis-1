#ifndef FOO_GUARD_FOR_UTIL   /* Include guard */
#define FOO_GUARD_FOR_UTIL

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "myRandom.h"

uint64_t **getArray(size_t size);
void printArray(uint64_t** A, size_t size);
void fillWithRandom(uint64_t** A, size_t size, size_t limit);




#endif // FOO_GUARD_FOR_MYRANDOM
