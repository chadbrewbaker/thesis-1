#ifndef FOO_GUARD_FOR_NAIVE /* Include guard */
#define FOO_GUARD_FOR_NAIVE

#include <stdint.h>
#include <stdlib.h>
#include "util.h"
#include "defines.h"


void matrixMultiplication(my_type **, my_type **, my_type **, size_t);
void matrixMultiplicationTiled(my_type **, my_type **, my_type **, size_t);
void matrixMultiplicationFixed(my_type **, my_type **, my_type **);
#endif // FOO_GUARD_FOR_MYRANDOM
