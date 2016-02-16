#include "naive.h"
#include "util.h"

int main(int argc, char const *argv[]) {
  size_t arraySize = 512;
  uint64_t** A = getArray(arraySize);
  fillWithRandom(A, arraySize, 100);
  // printArray(A, arraySize);
  uint64_t** B = getArray(arraySize);
  fillWithRandom(B, arraySize, 100);
  uint64_t** C = matrixMultiplication(A, B, arraySize);
  // printArray(C, arraySize);
  printf("%lu\n", C[0][0]);
  return 0;
}
