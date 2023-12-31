CC     = gcc
CDFLAGS = -g -Wall -Werror -pedantic-errors -Iinclude
SRC_DIR = ./src
INCLUDE_DIR = ./include
BUILD_DIR = ./build
CFLAGS = -Wall -Werror -pedantic-errors -Iinclude -O3

.PHONY: all clean debug
all: build
build: $(SRC_DIR)/sort.c $(SRC_DIR)/quicksort.c
	mkdir -p $(BUILD_DIR)/obj $(BUILD_DIR)/release
	$(CC) $(CFLAGS) $(SRC_DIR)/quicksort.c -c -o $(BUILD_DIR)/obj/quicksort.o
	$(CC) $(CFLAGS) $(SRC_DIR)/sort.c $(BUILD_DIR)/obj/quicksort.o -o $(BUILD_DIR)/release/sort
clean:
	rm -rf $(BUILD_DIR)
debug: $(SRC_DIR)/sort.c $(SRC_DIR)/quicksort.c
	mkdir -p $(BUILD_DIR)/obj $(BUILD_DIR)/debug
	$(CC) $(CDFLAGS) $(SRC_DIR)/quicksort.c -c -o $(BUILD_DIR)/obj/quicksort.o
	$(CC) $(CDFLAGS) $(SRC_DIR)/sort.c $(BUILD_DIR)/obj/quicksort.o -o $(BUILD_DIR)/debug/sort