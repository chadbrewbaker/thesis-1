#include "util.h"

my_type **getArray(size_t size) {
  my_type **arr;
 int err =0;
  //arr = (my_type **)aligned_alloc(32, sizeof(my_type *) * size);
  err = posix_memalign((void **) &arr, 32, sizeof(my_type *) * size);
  //arr[0] = (my_type *)aligned_alloc(32, sizeof(my_type) * size * size);
  err = posix_memalign((void **) &(arr[0]), 32, sizeof(my_type) * size * size);
  for (size_t i = 0; i < size; i++)
    arr[i] = (*arr + size * i);
  return arr;
}

void printArray(my_type **A, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      printf("%f ", A[i][j]);
    }
    printf("\n");
  }
  printf("--------------------------------------------------------------\n");
}

void fillWithRandom(my_type **A, size_t size, size_t limit) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      A[i][j] = xorshift128plus() % limit;
    }
  }
}

// void addNew(my_type **A, my_type **B, my_type **C, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       C[i][j] = A[i][j] + B[i][j];
//     }
//   }
// }

void addNew(my_type *A, my_type *B, my_type *C, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    C[i] = A[i] + B[i];
  }
}

void addLeft(my_type *A, my_type *B, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    A[i] += B[i];
  }
}
//
// void addLeft(my_type *A, my_type *B, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       A[i][j] += B[i][j];
//     }
//   }
// }

// void subNew(my_type *A, my_type *B, my_type *C, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       C[i][j] = A[i][j] - B[i][j];
//     }
//   }
// }

void subNew(my_type *A, my_type *B, my_type *C, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    C[i] = A[i] - B[i];
  }
}

void subLeft(my_type *A, my_type *B, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    A[i] -= B[i];
  }
}

// void subLeft(my_type *A, my_type *B, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       A[i][j] -= B[i][j];
//     }
//   }
// }

// void subRight(my_type *A, my_type *B, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       B[i][j] = A[i][j] - B[i][j];
//     }
//   }
// }


void subRight(my_type *A, my_type *B, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    B[i] = A[i] - B[i];
  }
}
