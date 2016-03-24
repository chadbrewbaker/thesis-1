#include "naive.h"
void matrixMultiplication(my_type **A, my_type **B, my_type **C,
                          size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      int sum = 0;
      for (size_t k = 0; k < size; k++) {
        sum += A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }
  return;
}

void matrixMultiplicationFixed(my_type const **__restrict A, my_type const **__restrict B, my_type **__restrict C) {
  for (size_t i = 0; i < FIXEDSIZE; i++) {
    for (size_t j = 0; j < FIXEDSIZE; j++) {
      int sum = 0;
      for (size_t k = 0; k < FIXEDSIZE; k++) {
        sum += A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }
  return;
}

void matrixMultiplicationTiled(my_type **A, my_type **B, my_type **C,
                               size_t size) {
  for (size_t i = 0; i < size; i += TILESIZE) {
    for (size_t j = 0; j < size; j += TILESIZE) {
      for (size_t k = 0; k < size; k++) {
        for (size_t x = i; x < i + TILESIZE; x++) {
          for (size_t y = j; y < j + TILESIZE; y++) {
            C[x][y] += A[x][k] * B[k][y];
          }
        }
      }
    }
  }
  return;
}
