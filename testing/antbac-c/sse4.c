#include "header.h"

/* Generate a 2x2 double_32 matrix */
double_32 * double_matrix() {
  double_32 *ret = (double_32 *) aligned_alloc(32, sizeof(double_32) * 4);
  for(size_t i = 0; i < 4; i++){
    ret[i] = (rand() % 100)+1;
  }
  return ret;
}

/* Print the contents of two 2x2 double_32 matrices */
void print_d_2(const double_32 *__restrict a, const double_32 *__restrict b) {
    printf("%f\t%f\t|\t%f\t%f\n", a[0], a[1], b[0], b[1]);
    printf("%f\t%f\t|\t%f\t%f\n", a[2], a[3], b[2], b[3]);
    printf("\n");
}

/* Print the contents of a 2x2 double_32 matrix */
void print_d(const double_32 *__restrict a) {
  for(size_t y = 0; y < 2; y++){
    for(size_t x = 0; x < 2; x++){
      printf("%f\t", a[x+2*y]);
    }
    printf("\n");
  }
  printf("\n");
}

/* Perform tests on a 2x2 double_32 matrix */
void run_d() {
  double_32 *a = double_matrix();
  double_32 *b = double_matrix();
  double_32 *r = double_matrix();
  printf("Double 2x2:\n-----------\n");
  print_d_2(a, b);
  matrix_mul_2_2_double(a, b, r);
  print_d(r);
  printf("\n\n");
  free(a);
  free(b);
  free(r);
}

/* Generate a 4x4 float_32 matrix */
float_32 * float_matrix() {
  float_32 *ret = (float_32 *) aligned_alloc(32, sizeof(float_32) * 16);
  for(size_t i = 0; i < 16; i++){
    ret[i] = (rand() % 100)+1;
  }
  return ret;
}

/* Print the contents of two 2x2 double_32 matrices */
void print_f_2(const float_32 *__restrict a, const float_32 *__restrict b) {
    printf("%f\t%f\t%f\t%f\t|\t%f\t%f\t%f\t%f\t\n", a[0], a[1], a[2], a[3], b[0], b[1], b[2], b[3]);
    printf("%f\t%f\t%f\t%f\t|\t%f\t%f\t%f\t%f\t\n", a[4], a[5], a[6], a[7], b[4], b[5], b[6], b[7]);
    printf("%f\t%f\t%f\t%f\t|\t%f\t%f\t%f\t%f\t\n", a[8], a[9], a[10], a[11], b[8], b[9], b[10], b[11]);
    printf("%f\t%f\t%f\t%f\t|\t%f\t%f\t%f\t%f\t\n", a[12], a[13], a[14], a[15], b[12], b[13], b[14], b[15]);
    printf("\n");
}

/* Print the contents of a 4x4 float_32 matrix */
void print_f(const float_32 *__restrict a) {
  printf("%f\t%f\t%f\t%f\n", a[0], a[1], a[2], a[3]);
  printf("%f\t%f\t%f\t%f\n", a[4], a[5], a[6], a[7]);
  printf("%f\t%f\t%f\t%f\n", a[8], a[9], a[10], a[11]);
  printf("%f\t%f\t%f\t%f\n", a[12], a[13], a[14], a[15]);
  printf("\n");
}

/* Perform tests on a 4x4 float_32 matrix */
void run_f() {
  float_32 *a = float_matrix();
  float_32 *b = float_matrix();
  float_32 *r = float_matrix();
  printf("Float 4x4:\n-----------\n");
  print_f_2(a, b);
  matrix_mul_4_4_float(a, b, r);
  print_f(r);
  printf("\n\n");
  free(a);
  free(b);
  free(r);
}

int main(int argc, char const *argv[]) {
  srand(time(0));
  //run_d();
  run_f();
}
