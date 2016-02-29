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

#ifndef TILESIZE
#define TILESIZE 32
#endif

void matrixMultiplicationFixed(uint64_t **A, uint64_t **B, uint64_t **C){
  for (size_t i = 0; i < 64; i++) {
    for (size_t j = 0; j < 64; j++) {
      int sum = 0;
      for (size_t k = 0; k < 64; k++) {
        sum += A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }
  return;
}

void matrixMultiplicationTiled(uint64_t **A, uint64_t **B, uint64_t **C, size_t size){
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
