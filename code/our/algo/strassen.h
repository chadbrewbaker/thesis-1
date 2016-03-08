#ifndef FOO_GUARD_FOR_STRASSEN /* Include guard */
#define FOO_GUARD_FOR_STRASSEN

#include <stdint.h>
#include <stdlib.h>
#include "util.h"
#include "naive.h"
#include "defines.h"
#include "quad.h"


void strassen(my_type **, my_type **, my_type **, size_t);
void strassenQuad(Quad *A, Quad *B, Quad *C, size_t size);
#endif // FOO_GUARD_FOR_MYRANDOM
