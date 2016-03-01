#ifndef FOO_GUARD_FOR_UTIL /* Include guard */
#define FOO_GUARD_FOR_UTIL

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "myRandom.h"
#include "defines.h"


my_type **getArray(size_t);
void printArray(my_type **, size_t);
void fillWithRandom(my_type **, size_t, size_t);
void addNew(my_type **, my_type **, my_type **, size_t);
void addLeft(my_type **, my_type **, size_t);
void subNew(my_type **, my_type **, my_type **, size_t);
void subLeft(my_type **, my_type **, size_t);
void subRight(my_type **, my_type **, size_t);

#endif // FOO_GUARD_FOR_MYRANDOM
