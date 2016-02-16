#ifndef FOO_GUARD_FOR_NAIVE   /* Include guard */
#define FOO_GUARD_FOR_NAIVE

#include <stdint.h>
#include <stdlib.h>

uint64_t **matrixMultiplication(uint64_t** A, uint64_t** B, size_t size);
uint64_t **getArray(size_t size);
void printArray(uint64_t** A);

// uint64_t xorshift128plus();
// void seed128plus(uint64_t a, uint64_t b);


#endif // FOO_GUARD_FOR_MYRANDOM
