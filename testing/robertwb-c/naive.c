#include "naive.h"
uint64_t** matrixMultiplication(uint64_t** A, uint64_t** B, size_t size){
    uint64_t** C = getArray(size);
    for (size_t i = 0; i < size; i++) {
      for (size_t j = 0; j < size; j++) {
        int sum = 0;
        for (size_t k = 0; k < size; k++) {
          sum += A[i][k] * B[k][j];
        }
        C[i][j] = sum;
      }
    }

      // for i in range(n):
      //     for j in range(p):
      //         theSum = 0
      //         for k in range(m):
      //             theSum += A[i][k] * B[k][j]
      //         C[i][j] = theSum
    return C;
}

uint64_t** getArray(size_t size){
    uint64_t** arr;
    arr  = (uint64_t **)malloc(sizeof(uint64_t *) * size);
    arr[0] = (uint64_t *)malloc(sizeof(uint64_t) * size * size);

    for(size_t i = 0; i < size; i++)
        arr[i] = (*arr + size * i);
    return arr;
}

void printArray(uint64_t** A){
    
}
