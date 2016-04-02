#ifndef FOO_GUARD_FOR_NAIVE /* Include guard */
#define FOO_GUARD_FOR_NAIVE

#include <stdint.h>
#include <stdlib.h>
#include "util.h"
#include "defines.h"


void matrixMultiplication(my_type **, my_type **, my_type **, size_t);
void matrixMultiplicationTiled(my_type **, my_type **, my_type **, size_t);
void matrixMultiplicationFixed(const my_type **, const my_type **, my_type **);
void asmMulF64(const f32 *__restrict, const f32 *__restrict, f32 *__restrict);
void asmMulF128(const f32 *__restrict, const f32 *__restrict, f32 *__restrict);
void asmMulF256(const f32 *__restrict, const f32 *__restrict, f32 *__restrict);
void asmMul(const d32 *__restrict, const d32 *__restrict, d32 *__restrict);
void asmMul32(const d32 *__restrict, const d32 *__restrict, d32 *__restrict);
void asmMul128(const d32 *__restrict, const d32 *__restrict, d32 *__restrict);

#endif // FOO_GUARD_FOR_MYRANDOM
