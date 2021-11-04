CC = gcc
PROJECT_MANAGER = project
PRJOCET_BIN = listpost

# FLAGS
BUILD_FLAG = -lm
CFLAG = -Wall -std=c99
TEST_FLAG = -lcheck -lcheck -lm -lpthread -lrt -lsubunit -std=c99 -lsubunit -lgcov -coverage

BUILD_SRC = ./build/src
BUILD_TEST = ./build/test

BIN_SRC = $(shell find src -name "*.c")
BIN_OBJ = $(patsubst %.c,build/%.o,$(BIN_SRC))

NMAIN_SRC = $(shell find src -name "*.c"  ! -name "main_*" ! -name "m*")
NMAIN_OBJ = $(patsubst %.c,build/%.o,$(NMAIN_SRC))

# TESTING CONFIGURATION
TESTING_FILE = $(shell find test -name "*.c")
TESTING_OBJ = $(patsubst %.c,build/%.o,$(TESTING_FILE))

# SOURCE CODE TO OBJECT FILE
./build/src/%.o: ./src/%.c ./src/%.h
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $< -o $@

./build/src/%.o: ./src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $< -o $@

./build/test/%.o: ./test/%.c
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -fprofile-arcs -ftest-coverage -c $< -o $@

clear:
	@rm -rf build/* bin/*

# BINARY FILE
# ./bin/%: $(BUILD_SRC)/%.o
# 	@echo "Mode tanpa ADT"
# 	@$(CC) $^ -o $@ $(BUILD_FLAG)

./bin/%: $(BUILD_SRC)/m%.o $(BUILD_SRC)/%.o
	$(CC) -g $^ -o $@ $(BUILD_FLAG)

./bin/%: $(BUILD_SRC)/main_%.o $(BUILD_SRC)/%.o
	@$(CC) -g $^ -o $@ $(BUILD_FLAG)

./bin/test: ${TESTING_OBJ} $(NMAIN_OBJ)
	@$(CC) -g $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)

./bin/list_dp: $(BUILD_SRC)/list_dp.o  $(BUILD_SRC)/mlist_dp.o 
	@$(CC) -g $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)

./bin/list_circular: $(BUILD_SRC)/list_circular.o  $(BUILD_SRC)/mlist_circular.o 
	@$(CC) -g $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)


test: clean ./bin/test
	@./bin/test

tc:
	@project add tc

adt:
	@project add adt

%: ./bin/%
	@./$<
	@echo ""

clean: clear

all: ./bin/test ./bin/$(PROJECT_BIN)

vscode: ./bin/test

.PHONY: test clear all adt tc clean vscode ./bin/test