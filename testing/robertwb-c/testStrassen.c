#include "naive.h"
#include "util.h"
#include "strassen.h"

int main(int argc, char const *argv[]) {
  size_t arraySize = 16;
  uint64_t **A = getArray(arraySize);
  fillWithRandom(A, arraySize, 10);
  // printArray(A, arraySize);
  uint64_t **B = getArray(arraySize);
  fillWithRandom(B, arraySize, 10);
  uint64_t **C = getArray(arraySize);
  strassen(A, B, C, arraySize);
  matrixMultiplication(A, B, C, arraySize);
  printArray(C, arraySize);
  // printf("%lu\n", C[0][0]);
  return 0;
}