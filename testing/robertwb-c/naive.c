#include "naive.h"
void matrixMultiplication(uint64_t **A, uint64_t **B, uint64_t **C, size_t size){
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

void matrixMultiplicationTiled(uint64_t **A, uint64_t **B, uint64_t **C, size_t size){
  for (size_t i = 0; i < size; i += 4) {
    for (size_t j = 0; j < size; j += 4) {
      for (size_t k = 0; k < size; k++) {
        for (size_t x = 0; x < i + 4; x++) {
          for (size_t y = 0; y < j + 4; y++) {
            C[x][y] += A[x][k] * B[k][y];
          }
        }
      }
    }
  }
  return;
}
