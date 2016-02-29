#include "strassen.h"
void strassen(uint64_t **A, uint64_t **B, uint64_t **C, size_t size) {
  if (size < 128) {
    matrixMultiplicationFixed(A, B, C);
    return;
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
  free(A11[0]);
  free(A11);
  strassen(A12, B21, B11, mid);
  uint64_t **P2 = B11;
  strassen(S4, B22, B21, mid);
  uint64_t **P3 = B21;
  strassen(A22, T4, A12, mid);
  free(A22[0]);
  free(A22);
  uint64_t **P4 = A12;
  strassen(S1, T1, S4, mid);
  free(T1[0]);
  free(T1);
  free(S1[0]);
  free(S1);
  uint64_t **P5 = S4;
  strassen(S2, T2, B22, mid);
  free(S2[0]);
  free(S2);
  free(T2[0]);
  free(T2);
  uint64_t **P6 = B22;
  strassen(S3, T3, T4, mid);
  uint64_t **P7 = T4;
  free(S3[0]);
  free(S3);
  free(T3[0]);
  free(T3);

  //A22, T1, S1, S2, T2, S3, T3,
  //P6, P3
  addLeft(P2, P1, mid);
  uint64_t **U1 = P2;
  addLeft(P1, P6, mid);
  free(P6[0]);
  free(P6);
  uint64_t **U2 = P1;
  addLeft(P7, U2, mid);
  uint64_t **U3 = P7;
  addLeft(U2, P5, mid);
  uint64_t **U4 = U2;
  addLeft(U4, P3, mid);
  free(P3[0]);
  free(P3);
  uint64_t **U5 = U4;
  subRight(U3, P4, mid);
  uint64_t **U6 = P4;
  addLeft(U3, P5, mid);
  uint64_t **U7 = U3;
  free(P5[0]);
  free(P5);

  for (size_t i = 0; i < mid; i++) {
    for (size_t j = 0; j < mid; j++) {
      C[i][j] = U1[i][j];
      C[i][j+mid] = U5[i][j];
      C[i+mid][j] = U6[i][j];
      C[i+mid][j+mid] = U7[i][j];
    }
  }
  free(U1[0]);
  free(U1);
  free(U5[0]);
  free(U5);
  free(U6[0]);
  free(U6);
  free(U7[0]);
  free(U7);

  return;
}
