#include "util.h"

uint64_t **getArray(size_t size) {
  uint64_t **arr;
  arr = (uint64_t **)malloc(sizeof(uint64_t *) * size);
  arr[0] = (uint64_t *)malloc(sizeof(uint64_t) * size * size);

  for (size_t i = 0; i < size; i++)
    arr[i] = (*arr + size * i);
  return arr;
}

void printArray(uint64_t **A, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      printf("%lu ", A[i][j]);
    }
    printf("\n");
  }
  printf("--------------------------------------------------------------\n");
}

void fillWithRandom(uint64_t **A, size_t size, size_t limit) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      A[i][j] = xorshift128plus() % limit;
    }
  }
}

void addNew(uint64_t **A, uint64_t **B, uint64_t **C, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void addLeft(uint64_t **A, uint64_t **B, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      A[i][j] += B[i][j];
    }
  }
}

void subNew(uint64_t **A, uint64_t **B, uint64_t **C, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
}

void subLeft(uint64_t **A, uint64_t **B, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      A[i][j] -= B[i][j];
    }
  }
}

void subRight(uint64_t **A, uint64_t **B, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      B[i][j] = A[i][j] - B[i][j];
    }
  }
}
