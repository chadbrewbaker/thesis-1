#include <stdio.h>
#include <stdlib.h>

typedef double double_32 __attribute__((aligned(32)));

/* Multiply two arrays into one array */
void fct(double_32 *__restrict r, const double_32 *__restrict a, const double_32 *__restrict b) {
  for (unsigned i = 0; i < 4; ++i)
    r[i] = a[i] * b[i];
}

/* Takes a pointer to an integer and shifts the value 2 to the right */
void shift(int *i) {
  *i = *i >> 2;
}

/* Add the sum of an array into an address */
void sum(double_32 *__restrict r, const double_32 *__restrict a) {
  *r = 0; 
  for (unsigned i = 0; i < 4; ++i)
    *r += a[i];
}

/* The best example from the youtube-video */
void video(double_32 *__restrict r, const double_32 *__restrict a,
         const double_32 *__restrict b, double f) {
  for (unsigned i = 0; i < 128; ++i)
    r[i] = a[i] * f + b[i];
}

/* Code to allocate an array of double_32 */
double_32 * my_alloc(size_t elements) {
  return (double_32 *) aligned_alloc(32, sizeof(double_32) * elements);
}

/* Prints "Hello World" to stdout */
void printWorld() {
  printf("Hello World\n");
  return;
}

/* Transposes the 4x4 matrix a into the address of b */
void transpose(const double_32 *__restrict a, double_32 *__restrict b) {
  b[0] = a[0]; b[1] = a[4]; b[2] = a[8]; b[3] = a[12]; // Row 1
  b[4] = a[1]; b[5] = a[5]; b[6] = a[9]; b[7] = a[13]; // Row 2
  b[8] = a[2]; b[9] = a[6]; b[10] = a[10]; b[11] = a[14]; // Row 3
  b[12] = a[3]; b[13] = a[7]; b[14] = a[11]; b[15] = a[15]; // Row 4
  return;
}

/* Control-function that does nothing at all */
void doNothing() {
  return;
}

/* prototype for asembler function */
void vec_mul(double_32 *__restrict r, const double_32 *__restrict a, const double_32 *__restrict b);

int main() {
  double_32 *a = my_alloc(4);
  a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
  double_32 *b = my_alloc(4);
  b[0] = 10; b[1] = 10; b[2] = 10; b[3] = 10;
  double_32 *r = my_alloc(4);

  printf("a : %p\n", a);
  printf("b : %p\n", b);
  printf("r : %p\n", r);

  /* call the regular function */
  fct(r, a, b);
  for (int i = 0; i < 4; i++) {
    printf("%f\n", r[i]);
  }

  /* call the asembler function */
  vec_mul(r, a, b);
  for (int i = 0; i < 4; i++) {
    printf("%f\n", r[i]);
  }

  /* Call the sum function */
  sum(r, a);
  printf("%f\n", *r);

  free(a);
  free(b);
  free(r);

  return 0;
}
