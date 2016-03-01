#include "naive.h"
#include "util.h"
#include "strassen.h"

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#ifndef ARRAYSIZE
#define ARRAYSIZE 1024
#endif

int main() {
  size_t arraySize = ARRAYSIZE;
  uint64_t **A = getArray(arraySize);
  fillWithRandom(A, arraySize, 10);
  // printArray(A, arraySize);
  uint64_t **B = getArray(arraySize);
  fillWithRandom(B, arraySize, 10);
  uint64_t **C = getArray(arraySize);
  struct timeval stop, start;
  gettimeofday(&start, NULL);
  size_t LOOP_COUNT = 1;
  for (size_t i = 0; i < LOOP_COUNT; i++) {
    strassen(A, B, C, arraySize);
  }
  gettimeofday(&stop, NULL);
  unsigned long ms = ((stop.tv_sec - start.tv_sec) * 1000) +
                     (stop.tv_usec - start.tv_usec) / 1000;
  printf("took %lu\n", ms / LOOP_COUNT);
  // printArray(C, arraySize);
  // matrixMultiplication(A, B, C, arraySize);
  printArray(C, arraySize);
  // printf("%lu\n", C[0][0]);
  // printf("%lu\n", C[0][1]);
  // printf("%lu\n", C[1][0]);
  // printf("%lu\n", C[1][1]);
  free(A[0]);
  free(A);
  free(B[0]);
  free(B);
  free(C[0]);
  free(C);
  return 0;
}
