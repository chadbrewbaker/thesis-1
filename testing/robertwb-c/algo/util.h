#ifndef FOO_GUARD_FOR_UTIL /* Include guard */
#define FOO_GUARD_FOR_UTIL

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "myRandom.h"

uint64_t **getArray(size_t);
void printArray(uint64_t **, size_t);
void fillWithRandom(uint64_t **, size_t, size_t);
void addNew(uint64_t **, uint64_t **, uint64_t **, size_t);
void addLeft(uint64_t **, uint64_t **, size_t);
void subNew(uint64_t **, uint64_t **, uint64_t **, size_t);
void subLeft(uint64_t **, uint64_t **, size_t);
void subRight(uint64_t **, uint64_t **, size_t);

#endif // FOO_GUARD_FOR_MYRANDOM
