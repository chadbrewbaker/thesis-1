#include <stdio.h>
#include "myRandom.h"  /* Include the header here, to obtain the function declaration */

int main(int argc, char const *argv[]) {

    seed128plus(0x7468697369737365, 0x6372657473656564); //thisisse cretseed
    long y = xorshift128plus();
    for (size_t i = 0; i < 20; i++) {
      xorshift128plus();
    }
    printf("%lu\n", y);
    return 0;
}
