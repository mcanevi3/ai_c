CC := gcc
CFLAGS := -Wall -O2
# List all .c files in the directory
SRC := $(wildcard *.c)
# For main target: main.c + all except test.c
MAIN_SRC := main.c $(filter-out test.c main.c, $(SRC))
# For test target: test.c + all except main.c
TEST_SRC := test.c $(filter-out main.c test.c, $(SRC))
# Object files for main
MAIN_OBJ := $(MAIN_SRC:.c=.o)
# Object files for test
TEST_OBJ := $(TEST_SRC:.c=.o)
.PHONY: all clean
all: main test
# Build main executable
main: $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Build test executable
test: $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $^
# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o main test
