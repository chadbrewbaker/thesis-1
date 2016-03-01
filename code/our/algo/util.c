#include "util.h"

my_type **getArray(size_t size) {
  my_type **arr;
  arr = (my_type **)malloc(sizeof(my_type *) * size);
  arr[0] = (my_type *)malloc(sizeof(my_type) * size * size);

  for (size_t i = 0; i < size; i++)
    arr[i] = (*arr + size * i);
  return arr;
}

void printArray(my_type **A, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      printf("%lu ", A[i][j]);
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

void addNew(my_type **A, my_type **B, my_type **C, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    C[0][i] = A[0][i] + B[0][i];
  }
}

void addLeft(my_type **A, my_type **B, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    A[0][i] += B[0][i];
  }
}
//
// void addLeft(my_type **A, my_type **B, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       A[i][j] += B[i][j];
//     }
//   }
// }

// void subNew(my_type **A, my_type **B, my_type **C, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       C[i][j] = A[i][j] - B[i][j];
//     }
//   }
// }

void subNew(my_type **A, my_type **B, my_type **C, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    C[0][i] = A[0][i] - B[0][i];
  }
}

void subLeft(my_type **A, my_type **B, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    A[0][i] -= B[0][i];
  }
}

// void subLeft(my_type **A, my_type **B, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       A[i][j] -= B[i][j];
//     }
//   }
// }

// void subRight(my_type **A, my_type **B, size_t size) {
//   for (size_t i = 0; i < size; i++) {
//     for (size_t j = 0; j < size; j++) {
//       B[i][j] = A[i][j] - B[i][j];
//     }
//   }
// }


void subRight(my_type **A, my_type **B, size_t size) {
  for (size_t i = 0; i < size*size; i++) {
    B[0][i] = A[0][i] - B[0][i];
  }
}
