CC = gcc

# FLAGS
BUILD_FLAG = -lm
CFLAG = -Wall
TEST_FLAG = -lcheck -lcheck -lm -lpthread -lrt -lsubunit

BUILD_SRC = ./build/src
BUILD_TEST = ./build/test

BIN_SRC = $(shell find src -name "*.c")
BIN_OBJ = $(patsubst %.c,build/%.o,$(BIN_SRC))

# TESTING CONFIGURATION
TESTING_FILE = $(wildcard test/**/*.c) $(wildcard test/*.c)
TESTING_OBJ = $(patsubst %.c,build/%.o,$(TESTING_FILE))

NMAIN_SRC = $(shell find test -name "*.c")
NMAIN_OBJ = $(patsubst %.c,build/%.o,$(NMAIN_SRC))

# SOURCE CODE TO OBJECT FILE
./build/src/%.o: ./src/%.c ./src/%.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) -c $< -o $@

./build/src/%.o: ./src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) -c $< -o $@

./build/test/%.o: ./test/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAG) -c $< -o $@

clear:
	@rm -rf build/* bin/*

./bin/%: $(BUILD_SRC)/main_%.o $(BUILD_SRC)/%.o
	@$(CC) $^ -o $@ $(BUILD_FLAG)
	
# BUILDER PRAKTIKUM 01
./bin/test: ${TESTING_OBJ} $(NMAIN_OBJ)
	@$(CC) $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)

test: ./bin/test
	@./bin/test


./bin/garis: $(BUILD_SRC)/main_garis.o $(BUILD_SRC)/garis.o $(BUILD_SRC)/point.o
	@$(CC) $^ -o $@ $(BUILD_FLAG)

./bin/vector: $(BUILD_SRC)/main_vector.o $(BUILD_SRC)/vector.o $(BUILD_SRC)/point.o
	@$(CC) $^ -o $@ $(BUILD_FLAG)

time: ./bin/time
	@./bin/time

point: ./bin/point
	@./bin/point

garis: ./bin/garis
	@./bin/garis

vector: ./bin/vector
	@./bin/vector

all: ./bin/time ./bin/point

.PHONY: test clear time point all tested