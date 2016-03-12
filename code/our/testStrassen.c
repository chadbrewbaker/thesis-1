#include "algo/naive.h"
#include "algo/util.h"
#include "algo/strassen.h"
#include "algo/defines.h"

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main() {
  size_t arraySize = ARRAYSIZE;
  my_type **A = getArray(arraySize);
  fillWithRandom(A, arraySize, 10);
  // printArray(A, arraySize);
  my_type **B = getArray(arraySize);
  fillWithRandom(B, arraySize, 10);
  my_type **C = getArray(arraySize);
  struct timeval stop, start;
  size_t LOOP_COUNT = 1;
  gettimeofday(&start, NULL);
  for (size_t i = 0; i < LOOP_COUNT; i++) {
    strassen(A, B, C, arraySize);
  }
  gettimeofday(&stop, NULL);
  unsigned long ms = ((stop.tv_sec - start.tv_sec) * 1000) +
                     (stop.tv_usec - start.tv_usec) / 1000;
  printf("took %lu\n", ms / LOOP_COUNT);

  // printArray(C, arraySize);
  // matrixMultiplication(A, B, C, arraySize);
  // printArray(C, arraySize);
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




  Quad *quadA = newQuad(ARRAYSIZE);
  Quad *quadB = newQuad(ARRAYSIZE);
  Quad *quadC = newQuad(ARRAYSIZE);

  gettimeofday(&start, NULL);
  // size_t LOOP_COUNT = 1;
  for (size_t i = 0; i < LOOP_COUNT; i++) {
    strassenQuad(quadA, quadB, quadC, arraySize);
  }
  gettimeofday(&stop, NULL);
  ms = ((stop.tv_sec - start.tv_sec) * 1000) +
                     (stop.tv_usec - start.tv_usec) / 1000;
  printf("took %lu\n", ms / LOOP_COUNT);

  freeQuad(quadA);
  freeQuad(quadB);
  freeQuad(quadC);

  return 0;
}
