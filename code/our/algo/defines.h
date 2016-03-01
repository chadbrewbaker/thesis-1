#ifndef FOO_GUARD_FOR_DEFINES /* Include guard */
#define FOO_GUARD_FOR_DEFINES
#include <stdint.h>

#ifndef DATATYPE
#define DATATYPE 0
#endif

#if DATATYPE == 0
typedef uint64_t my_type;
#elif DATATYPE == 1
typedef uint64_t my_type;
#endif


#ifndef TILESIZE
#define TILESIZE 32
#endif
#ifndef FIXEDSIZE
#define FIXEDSIZE 64
#endif


#ifndef TRUNCATE
#define TRUNCATE 32
#endif

#ifndef ARRAYSIZE
#define ARRAYSIZE 512
#endif


#endif
