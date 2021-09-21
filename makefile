CC = g++
INCLUDES = -Isrc/components -Isrc/Board -Isrc/pieces -Isrc -Isrc/Application
OUTPUT = -o Chess
BOARD = ./src/Board/*.cc
PIECES = ./src/pieces/*.cc
COMPONENTS = ./src/components/*.cc
APPLICATION = ./src/Application/*.cc
MAIN = ./src/main.cc
STD = -std=c++17
OPTIMIZATION = -O3
WARNINGS = -Wall -Wextra -Wshadow -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -pedantic -Wconversion -Wsign-conversion -Wmisleading-indentation
all:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(PIECES) $(BOARD) $(APPLICATION) $(MAIN) $(STD)
alex:
	$(CC) $(STD) $(WARNINGS) $(OPTIMIZATION) $(INCLUDES) $(COMPONENTS) $(PIECES) $(BOARD) $(APPLICATION) $(MAIN)
board:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(BOARD) $(APPLICATION) $(MAIN) $(STD)
pieces:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(PIECES) $(APPLICATION) $(MAIN) $(STD)
