#ifndef FOO_GUARD_FOR_UTIL /* Include guard */
#define FOO_GUARD_FOR_UTIL

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "myRandom.h"

uint64_t **getArray(size_t size);
void printArray(uint64_t **A, size_t size);
void fillWithRandom(uint64_t **A, size_t size, size_t limit);
void addNew(uint64_t **A, uint64_t **B, uint64_t **C, size_t size);
void addLeft(uint64_t **A, uint64_t **B, size_t size);
void subNew(uint64_t **A, uint64_t **B, uint64_t **C, size_t size);
void subLeft(uint64_t **A, uint64_t **B, size_t size);
void subRight(uint64_t **A, uint64_t **B, size_t size);

#endif // FOO_GUARD_FOR_MYRANDOM
