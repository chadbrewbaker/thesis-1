#include "strassen.h"
void strassen(uint64_t **A, uint64_t **B, uint64_t **C, size_t size) {
  if (size < 16) {
    return matrixMultiplication(A, B, C, size);
  }
  size_t mid = size/2;
  uint64_t **A11 = getArray(mid);
  uint64_t **A12 = getArray(mid);
  uint64_t **A21 = getArray(mid);
  uint64_t **A22 = getArray(mid);
  uint64_t **B11 = getArray(mid);
  uint64_t **B12 = getArray(mid);
  uint64_t **B21 = getArray(mid);
  uint64_t **B22 = getArray(mid);

  for (size_t i = 0; i < mid; i++) {
    for (size_t j = 0; j < mid; j++) {
      A11[i][j] = A[i][j];
      A12[i][j] = A[i][j+mid];
      A21[i][j] = A[i+mid][j];
      A22[i][j] = A[i+mid][j+mid];
      B11[i][j] = B[i][j];
      B12[i][j] = B[i][j+mid];
      B21[i][j] = B[i+mid][j];
      B22[i][j] = B[i+mid][j+mid];
    }
  }

  uint64_t **S1 = getArray(mid);
  uint64_t **S2 = getArray(mid);

  addNew(A21, A22, S1, mid);
  subNew(S1, A11, S2, mid);

  subRight(A11, A21, mid);
  uint64_t **S3 = A21;

  uint64_t **T1 = getArray(mid);
  uint64_t **T2 = getArray(mid);
  subNew(B12, B11, T1, mid);
  subNew(B22, T1, T2, mid);

  subRight(B22, B12, mid);
  uint64_t **T3 = B12;

  uint64_t **S4 = getArray(mid);
  uint64_t **T4 = getArray(mid);
  subNew(A12, S2, S4, mid);
  subNew(T2, B21, T4, mid);

  uint64_t **P1 = getArray(mid);
  strassen(A11, B11, P1, mid);
  strassen(A12, B21, B11, mid);
  uint64_t **P2 = B11;
  strassen(S4, B22, B21, mid);
  uint64_t **P3 = B21;
  strassen(A22, T4, A12, mid);
  uint64_t **P4 = A12;
  strassen(S1, T1, S4, mid);
  uint64_t **P5 = S4;
  strassen(S2, T2, B22, mid);
  uint64_t **P6 = B22;
  strassen(S3, T3, T4, mid);
  uint64_t **P7 = T4;

  //A22, T1, S1, S2, T2, S3, T3, P6, P3
  addLeft(P2, P1, mid);
  uint64_t **U1 = P2;
  addLeft(P1, P6, mid);
  uint64_t **U2 = P1;
  addLeft(P7, U2, mid);
  uint64_t **U3 = P7;
  addLeft(U2, P5, mid);
  uint64_t **U4 = U2;
  addLeft(U4, P3, mid);
  uint64_t **U5 = U4;
  subRight(U3, P4, mid);
  uint64_t **U6 = P4;
  addLeft(U3, P5, mid);
  uint64_t **U7 = U3;

  printArray(U1, mid);
  printArray(U5, mid);
  printArray(U6, mid);
  printArray(U7, mid);
  // # printMatrix(U1)
  // # print()
  // # printMatrix(U6)
  // # print()
  // # printMatrix(U5)
  // # print()
  // # printMatrix(U7)
  //
  // U1.extend(U6)
  // U5.extend(U7)
  //
  // # print()
  // # printMatrix(U1)
  // # print()
  // # printMatrix(U5)
  // # print()
  // for i in range(len(U1)):
  //     U1[i].extend(U5[i])
  // # printMatrix(U1)
  // return U1

  return;
}
