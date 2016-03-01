#include "algo/naive.h"
#include "algo/util.h"

#ifndef ARRAYSIZE
#define ARRAYSIZE 1024
#endif

int main() {
  size_t arraySize = ARRAYSIZE;
  uint64_t **A = getArray(arraySize);
  fillWithRandom(A, arraySize, 100);
  // printArray(A, arraySize);
  uint64_t **B = getArray(arraySize);
  fillWithRandom(B, arraySize, 100);
  // uint64_t **C = getArray(arraySize);
  // matrixMultiplication(A, B, C, arraySize);
  // printf("%lu\n", C[0][0]);
  // printArray(C, arraySize);
  uint64_t **D = getArray(arraySize);
  matrixMultiplicationTiled(A, B, D, arraySize);
  printf("%lu\n", D[0][0]);
  // printArray(D, arraySize);
  return 0;
}
