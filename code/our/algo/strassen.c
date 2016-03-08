#include "strassen.h"

void strassen(my_type **A, my_type **B, my_type **C, size_t size) {
  // if (size == FIXEDSIZE) {
  //   matrixMultiplicationTiled(A, B, C);
  //   return;
  // }
  // if (size == FIXEDSIZE) {
  //   matrixMultiplicationFixed(A, B, C);
  //   return;
  // }
  if (size == FIXEDSIZE) {
    asmMul(*A, *B, *C);
    return;
  }
  size_t mid = size / 2;
  my_type **A11 = getArray(mid);
  my_type **A12 = getArray(mid);
  my_type **A21 = getArray(mid);
  my_type **A22 = getArray(mid);
  my_type **B11 = getArray(mid);
  my_type **B12 = getArray(mid);
  my_type **B21 = getArray(mid);
  my_type **B22 = getArray(mid);

  for (size_t i = 0; i < mid; i++) {
    for (size_t j = 0; j < mid; j++) {
      A11[i][j] = A[i][j];
      A12[i][j] = A[i][j + mid];
      A21[i][j] = A[i + mid][j];
      A22[i][j] = A[i + mid][j + mid];
      B11[i][j] = B[i][j];
      B12[i][j] = B[i][j + mid];
      B21[i][j] = B[i + mid][j];
      B22[i][j] = B[i + mid][j + mid];
    }
  }

  my_type **S1 = getArray(mid);
  my_type **S2 = getArray(mid);

  addNew(*A21, *A22, *S1, mid);
  subNew(*S1, *A11, *S2, mid);

  subRight(*A11, *A21, mid);
  my_type **S3 = A21;

  my_type **P1 = getArray(mid);
  strassen(A11, B11, P1, mid);
  my_type **T1 = A11;
  subNew(*B12, *B11, *T1, mid);

  my_type **T2 = getArray(mid);
  subNew(*B22, *T1, *T2, mid);

  subRight(*B22, *B12, mid);
  my_type **T3 = B12;

  my_type **S4 = getArray(mid);
  my_type **T4 = getArray(mid);
  subNew(*A12, *S2, *S4, mid);
  subNew(*T2, *B21, *T4, mid);

  strassen(A12, B21, B11, mid);
  my_type **P2 = B11;
  strassen(S4, B22, B21, mid);
  my_type **P3 = B21;
  strassen(A22, T4, A12, mid);
  free(A22[0]);
  free(A22);
  my_type **P4 = A12;
  strassen(S1, T1, S4, mid);
  free(T1[0]);
  free(T1);
  free(S1[0]);
  free(S1);
  my_type **P5 = S4;
  strassen(S2, T2, B22, mid);
  free(S2[0]);
  free(S2);
  free(T2[0]);
  free(T2);
  my_type **P6 = B22;
  strassen(S3, T3, T4, mid);
  my_type **P7 = T4;
  free(S3[0]);
  free(S3);
  free(T3[0]);
  free(T3);

  // A22, T1, S1, S2, T2, S3, T3,
  // P6, P3
  addLeft(*P2, *P1, mid);
  my_type **U1 = P2;
  addLeft(*P1, *P6, mid);
  free(P6[0]);
  free(P6);
  my_type **U2 = P1;
  addLeft(*P7, *U2, mid);
  my_type **U3 = P7;
  addLeft(*U2, *P5, mid);
  my_type **U4 = U2;
  addLeft(*U4, *P3, mid);
  free(P3[0]);
  free(P3);
  my_type **U5 = U4;
  subRight(*U3, *P4, mid);
  my_type **U6 = P4;
  addLeft(*U3, *P5, mid);
  my_type **U7 = U3;
  free(P5[0]);
  free(P5);

  for (size_t i = 0; i < mid; i++) {
    for (size_t j = 0; j < mid; j++) {
      C[i][j] = U1[i][j];
      C[i][j + mid] = U5[i][j];
      C[i + mid][j] = U6[i][j];
      C[i + mid][j + mid] = U7[i][j];
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

void strassenQuad(Quad *A, Quad *B, Quad *C, size_t size) {
  // if (size == FIXEDSIZE) {
  //   matrixMultiplicationTiled(A, B, C);
  //   return;
  // }
  // if (size == FIXEDSIZE) {
  //   matrixMultiplicationFixed(A, B, C);
  //   return;
  // }
  if (size == FIXEDSIZE) {
    asmMul(A->matrix, B->matrix, C->matrix);
    return;
  }
  size_t mid = size / 2;
  Quad *A11 = A->children[0];
  Quad *A12 = A->children[1];
  Quad *A21 = A->children[2];
  Quad *A22 = A->children[3];
  Quad *B11 = B->children[0];
  Quad *B12 = B->children[1];
  Quad *B21 = B->children[2];
  Quad *B22 = B->children[3];

  Quad *S1 = B->children[0];
  Quad *S2 = B->children[1];

  addNew(A21->matrix, A22->matrix, S1->matrix, mid);
  subNew(S1->matrix, A11->matrix, S2->matrix, mid);

  subRight(A11->matrix, A21->matrix, mid);
  Quad *S3 = A21;

  Quad *P1 = B->children[2];
  strassenQuad(A11, B11, P1, mid);
  Quad *T1 = A11;
  subNew(B12->matrix, B11->matrix, T1->matrix, mid);

  Quad *T2 = B->children[3];
  subNew(B22->matrix, T1->matrix, T2->matrix, mid);

  subRight(B22->matrix, B12->matrix, mid);
  Quad *T3 = B12;

  Quad *S4 = newQuad(mid);
  Quad *T4 = newQuad(mid);
  subNew(A12->matrix, S2->matrix, S4->matrix, mid);
  subNew(T2->matrix, B21->matrix, T4->matrix, mid);

  strassenQuad(A12, B21, B11, mid);
  Quad *P2 = B11;
  strassenQuad(S4, B22, B21, mid);
  Quad *P3 = B21;
  strassenQuad(A22, T4, A12, mid);
  // free(A22[0]);
  // free(A22);
  Quad *P4 = A12;
  strassenQuad(S1, T1, S4, mid);
  // free(T1[0]);
  // free(T1);
  // free(S1[0]);
  // free(S1);
  Quad *P5 = S4;
  strassenQuad(S2, T2, B22, mid);
  // free(S2[0]);
  // free(S2);
  // free(T2[0]);
  // free(T2);
  Quad *P6 = B22;
  strassenQuad(S3, T3, T4, mid);
  Quad *P7 = T4;
  // free(S3[0]);
  // free(S3);
  // free(T3[0]);
  // free(T3);

  // A22, T1, S1, S2, T2, S3, T3,
  // P6, P3
  addLeft(P2->matrix, P1->matrix, mid);
  Quad *U1 = P2;
  addLeft(P1->matrix, P6->matrix, mid);
  // free(P6[0]);
  // free(P6);
  Quad *U2 = P1;
  addLeft(P7->matrix, U2->matrix, mid);
  Quad *U3 = P7;
  addLeft(U2->matrix, P5->matrix, mid);
  Quad *U4 = U2;
  addLeft(U4->matrix, P3->matrix, mid);
  // free(P3[0]);
  // free(P3);
  Quad *U5 = U4;
  subRight(U3->matrix, P4->matrix, mid);
  Quad *U6 = P4;
  addLeft(U3->matrix, P5->matrix, mid);
  Quad *U7 = U3;
  // free(P5[0]);
  // free(P5);
  //

  C->children[0] = U1;
  C->children[1] = U5;
  C->children[2] = U6;
  C->children[3] = U7;


  // 1 5
  // 6 7
  // for (size_t i = 0; i < mid; i++) {
  //   for (size_t j = 0; j < mid; j++) {
  //     C[i][j] = U1[i][j];
  //     C[i][j + mid] = U5[i][j];
  //     C[i + mid][j] = U6[i][j];
  //     C[i + mid][j + mid] = U7[i][j];
  //   }
  // }
  // free(U1[0]);
  // free(U1);
  // free(U5[0]);
  // free(U5);
  // free(U6[0]);
  // free(U6);
  // free(U7[0]);
  // free(U7);

  return;
}
