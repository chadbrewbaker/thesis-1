#include <stdio.h>
#include <stdlib.h>

typedef double double_32 __attribute__((aligned(32)));

double_32 * my_alloc(int elements);
void asmMul32(const double_32 *__restrict a, const double_32 *__restrict b, double_32 *__restrict c);

int main() {
  double_32 *a = my_alloc(32*32);
  int counter = 1;
  for (int i = 0; i < 32; i++) {
    for (size_t j = 0; j < 32; j++) {
      a[j+i*32] = counter++;
    }
  }
  double_32 *b = my_alloc(32*32);
  for (int i = 0; i < 32; i++) {
    for (size_t j = 0; j < 32; j++) {
      b[j+i*32] = 10;
    }
  }
  double_32 *c = my_alloc(32*32);

/* Call the assembler function */
asmMul32(a, b, c);
for (int i = 0; i < 32; i++) {
  for (size_t j = 0; j < 32; j++) {
    printf("%f ", c[j+i*32]);
  }
  printf("\n");
}

free(a);
free(b);
free(c);

return 0;
}
