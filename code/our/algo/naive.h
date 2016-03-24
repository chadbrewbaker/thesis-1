#ifndef FOO_GUARD_FOR_NAIVE /* Include guard */
#define FOO_GUARD_FOR_NAIVE

#include <stdint.h>
#include <stdlib.h>
#include "util.h"
#include "defines.h"


void matrixMultiplication(my_type **, my_type **, my_type **, size_t);
void matrixMultiplicationTiled(my_type **, my_type **, my_type **, size_t);
void matrixMultiplicationFixed(const my_type **, const my_type **, my_type **);
void asmMul(const my_type *__restrict, const my_type *__restrict, my_type *__restrict);
void asmMul32(const my_type *__restrict, const my_type *__restrict, my_type *__restrict);
void asmMul128(const my_type *__restrict, const my_type *__restrict, my_type *__restrict);

#endif // FOO_GUARD_FOR_MYRANDOM
