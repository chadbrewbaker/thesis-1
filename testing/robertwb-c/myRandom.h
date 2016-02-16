#ifndef FOO_GUARD_FOR_MYRANDOM   /* Include guard */
#define FOO_GUARD_FOR_MYRANDOM

#include <stdint.h>
uint64_t xorshift128plus();
void seed128plus(uint64_t a, uint64_t b);


#endif // FOO_GUARD_FOR_MYRANDOM
