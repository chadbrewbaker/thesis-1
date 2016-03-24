#include "algo/naive.h"
#include "algo/util.h"
#include "algo/defines.h"

int main() {
  size_t arraySize = FIXEDSIZE;
  my_type **D = getArray(arraySize);
  my_type **C = getArray(arraySize);
  my_type **A = getArray(arraySize);
  my_type **B = getArray(arraySize);
  // printArray(A, arraySize);
  fillWithRandom(A, arraySize, 100);
  fillWithRandom(B, arraySize, 100);
  // printf("%lu\n", C[0][0]);
  // printArray(C, arraySize);
  // my_type *a = *A;
  // my_type *b = *B;
  // for (size_t i = 0; i < FIXEDSIZE*FIXEDSIZE; i++) {
  //   a[i] = i;
  //   b[i] = i;
  // }
  // a[0] = 2;
  matrixMultiplication(A, B, D, arraySize);
  printf("before ASM\n");
  asmMul32(*A, *B, *C);
  printf("after ASM\n");
  for (size_t i = 0; i < 16; i++) {
    for (size_t j = 0; j < 16; j++) {
      printf("%.0f, ", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("\n");
  for (size_t i = 0; i < 16; i++) {
    for (size_t j = 0; j < 16; j++) {
      printf("%.0f, ", B[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("\n");
  for (size_t i = 0; i < 16; i++) {
    for (size_t j = 0; j < 16; j++) {
      printf("%.0f, ", C[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("\n");
  for (size_t i = 0; i < 16; i++) {
    for (size_t j = 0; j < 16; j++) {
      printf("%.0f, ", D[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("\n");
  for (size_t i = 0; i < 32; i++) {
    for (size_t j = 0; j < 32; j++) {
      if (D[i][j] != C[i][j]) {
        printf("ERROR at %lu and %lu %.0f != %.0f \n", i, j, D[i][j],C[i][j]);
      }
    }
  }
  // printf("%.0f, ", C[1][0]);
  // printf("%.0f\n", C[1][1]);
  // printArray(D, arraySize);
  return 0;
}
