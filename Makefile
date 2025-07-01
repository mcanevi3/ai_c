CC := gcc
CFLAGS := -Wall -O2
# List all .c files in the directory
SRC := $(wildcard *.c)
MAIN_SRC := main.c $(filter-out test.c main.c neurons.c, $(SRC))
TEST_SRC := test.c $(filter-out main.c test.c neurons.c, $(SRC))
NEURONS_SRC := neurons.c $(filter-out main.c test.c neurons.c, $(SRC))
# Object files 
MAIN_OBJ := $(MAIN_SRC:.c=.o)
TEST_OBJ := $(TEST_SRC:.c=.o)
NEURONS_OBJ := $(NEURONS_SRC:.c=.o)
.PHONY: all clean
all: main test neurons
# Build main executable
main: $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^
# Build test executable
test: $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $^
# Build neurons executable
neurons: $(NEURONS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^
show:
	@echo OS is $(OS)
	@echo RM is $(RM)
# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
ifeq ($(OS),Windows_NT)
RM = cmd /C del /Q /F
EXE = .exe
NULL = nul
else
RM = rm -f
EXE =
NULL = /dev/null
endif

clean:
	-$(RM) *.o main$(EXE) test$(EXE) neurons$(EXE) 2>$(NULL)