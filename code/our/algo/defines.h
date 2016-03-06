#ifndef FOO_GUARD_FOR_DEFINES /* Include guard */
#define FOO_GUARD_FOR_DEFINES
#include <stdint.h>

#ifndef DATATYPE
#define DATATYPE 0
#endif

#if DATATYPE == 0
typedef uint64_t my_type __attribute__((aligned(32)));
#elif DATATYPE == 1
typedef uint32_t my_type __attribute__((aligned(32)));
#elif DATATYPE == 2
typedef float my_type __attribute__((aligned(32)));
#elif DATATYPE == 3
typedef double my_type __attribute__((aligned(32)));
#endif


#ifndef TILESIZE
#define TILESIZE 16
#endif
#ifndef FIXEDSIZE
#define FIXEDSIZE 64
#endif

// truncate and fixedsize needs to be the same value
// SIZE replaced with ARRAYSIZE

#ifndef TRUNCATE
#define TRUNCATE 64
#endif

#ifndef ARRAYSIZE
#define ARRAYSIZE 1024
#endif


#endif
