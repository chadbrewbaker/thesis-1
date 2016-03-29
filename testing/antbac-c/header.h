#include <stdio.h>
#include <stdlib.h>

typedef double double_32 __attribute__((aligned(32)));
typedef float float_32 __attribute__((aligned(32)));
void transpose_2_2_double(double_32 *__restrict);
void transpose_4_4_float(float_32 *__restrict);
