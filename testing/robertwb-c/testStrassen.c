#include "naive.h"
#include "util.h"
#include "strassen.h"

int main() {
  size_t arraySize = 1024;
  uint64_t **A = getArray(arraySize);
  fillWithRandom(A, arraySize, 10);
  // printArray(A, arraySize);
  uint64_t **B = getArray(arraySize);
  fillWithRandom(B, arraySize, 10);
  uint64_t **C = getArray(arraySize);
  strassen(A, B, C, arraySize);
  // printArray(C, arraySize);
  // matrixMultiplication(A, B, C, arraySize);
  // printArray(C, arraySize);
  // printf("%lu\n", C[0][0]);
  free(A[0]);
  free(A);
  free(B[0]);
  free(B);
  free(C[0]);
  free(C);
  return 0;
}
