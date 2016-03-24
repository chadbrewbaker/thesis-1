/* Includes */
#include <unistd.h> /* Symbolic Constants */
#include <stdio.h> /* Input/Output */
#include <stdlib.h> /* General Utilities */
#include <sys/wait.h>
#include <pthread.h>

typedef double double_32 __attribute__((aligned(32)));

double_32 *A;
double_32 *B;
double_32 *D;
double_32 *E;

/* Code to allocate an array of double_32 */
double_32 * my_alloc(size_t elements) {
  return (double_32 *) aligned_alloc(32, sizeof(double_32) * elements);
}

void matrixMultiplication(double_32 *A, double_32 *B, double_32 *C) {
  for (size_t i = 0; i < 64; i++) {
    for (size_t j = 0; j < 64; j++) {
      double_32 sum = 0;
      for (size_t k = 0; k < 64; k++) {
        sum += A[i*64+k] * B[j*64+k];
      }
      C[64*i+j] = sum;
    }
  }
  return;
}

void compare(double_32 *a, double_32 *b) {
  for (size_t i = 0; i < 64 * 64; i++) {
    if(a[i] != b[i]) {
      printf("Error! i = %lu A was : %f B was : %f\n", i, a[i], b[i]);
      printf("Error! pA = %p pB = %p\n", a, b);
      return;
    }
  }
}

void* my_fun(void *ptr) {
  matrixMultiplication(A, B, D);
  printf("Exiting child thread\n");
  pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {

  pthread_t child;
  void *status;

  A = my_alloc(64*64);
  B = my_alloc(64*64);
  D = my_alloc(64*64);
  E = my_alloc(64*64);

  int index = 0;
  for (size_t x = 0; x < 64; x++) {
    for (size_t y = 0; y < 64; y++) {
      A[index] = (double_32) (rand() % 10);
      B[index] = (double_32) (rand() % 10);
      D[index] = 0;
      E[index] = 0;
      index++;
    }
  }

  // Child
  pthread_create(&child, NULL, &my_fun, NULL);

  // Parent
  matrixMultiplication(A, B, E);
  pthread_join(child, &status);

  compare(D, E);

  return 0;
}
