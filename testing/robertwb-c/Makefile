SOURCES ?= strassen.c util.c naive.c myRandom.c
GCCFLAGS ?= -O2 -march=native -funroll-loops --param max-unroll-times=4 -std=c99 -Wall -Wextra
ICCFLAGS ?= -fast -ipo -no-prec-div -static -opt-prefetch -unroll-aggressive -march=native -std=c99 -Wall -Wextra

CC	= gcc
# CC	= icc
