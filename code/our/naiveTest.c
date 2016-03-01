#include "algo/naive.h"
#include "algo/util.h"
#include "algo/defines.h"


#ifndef ARRAYSIZE
#define ARRAYSIZE 1024
#endif

int main() {
  size_t arraySize = ARRAYSIZE;
  my_type **A = getArray(arraySize);
  fillWithRandom(A, arraySize, 100);
  // printArray(A, arraySize);
  my_type **B = getArray(arraySize);
  fillWithRandom(B, arraySize, 100);
  // my_type **C = getArray(arraySize);
  // matrixMultiplication(A, B, C, arraySize);
  // printf("%lu\n", C[0][0]);
  // printArray(C, arraySize);
  my_type **D = getArray(arraySize);
  matrixMultiplicationTiled(A, B, D, arraySize);
  printf("%lu\n", D[0][0]);
  // printArray(D, arraySize);
  return 0;
}
