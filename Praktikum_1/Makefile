CC = gcc

# FLAGS
BUILD_FLAG = -lm
CFLAG = -Wall
TEST_FLAG = -lcheck -lcheck -lm -lpthread -lrt -lsubunit

BUILD_SRC = ./build/src
BUILD_TEST = ./build/test

BIN_SRC = $(wildcard src/**/*.c) $(wildcard src/*.c)
BIN_OBJ = $(patsubst %.c,build/%.o,$(BIN_SRC))

# TESTING CONFIGURATION
TESTING_FILE = $(wildcard test/**/*.c) $(wildcard test/*.c)
TESTING_OBJ = $(patsubst %.c,build/%.o,$(TESTING_FILE))

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

# BUILDER PRAKTIKUM 01
./bin/test: ${TESTING_OBJ} $(BUILD_SRC)/point.o $(BUILD_SRC)/time.o
	@$(CC) $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)

test: ./bin/test
	@./bin/test

./bin/point: $(BUILD_SRC)/main_point.o $(BUILD_SRC)/point.o
	@$(CC) $^ -o $@ $(BUILD_FLAG)

./bin/time: $(BUILD_SRC)/main_time.o $(BUILD_SRC)/time.o
	@$(CC) $^ -o $@ $(BUILD_FLAG)

time: ./bin/time
	@./bin/time

point: ./bin/point
	@./bin/point

all: ./bin/time ./bin/point

.PHONY: test clear time point all