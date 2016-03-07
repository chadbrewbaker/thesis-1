SOURCES ?= strassen.c util.c naive.c myRandom.c

FLAGS ?= -O2 -march=native -funroll-loops --param max-unroll-times=4 -std=c11 -Wall -Wextra
CC	= gcc

# FLAGS ?= -fast -ipo -no-prec-div -static -opt-prefetch -unroll-aggressive -march=native -std=c11 -Wall -Wextra
# CC	= icc
FILES := $(wildcard algo/*.c)
ASM := $(wildcard algo/*.s)
HEADERS := $(wildcard algo/*.h)


print_flags:
	@echo "FILES  := $(FILES)"
	@echo "FLAGS  := $(FLAGS)"
	@echo "HEADERS  := $(HEADERS)"



$%.c: $(FILES) $(ASM) $(HEADERS) $^
	$(CC) $(FLAGS) $^ $(FILES) $(ASM) -o $@.out
	# @echo $(CC) $(FLAGS) $^ $(FILES) -o $@

clean:
	\rm -rf *.out *.o *.d
