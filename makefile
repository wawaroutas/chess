CC = g++
INCLUDES = -Isrc/components -Isrc/Board -Isrc/pieces -Isrc
OUTPUT = -o Chess
BOARD = ./src/Board/*.cc
PIECES = ./src/pieces/*.cc
COMPONENTS = ./src/components/*.cc
MAIN = ./src/main.cc
STD = -std=c++17
all:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(PIECES) $(BOARD) $(MAIN) $(STD)
alex:
	g++ -std=c++17 -Wall -Wextra -Wshadow -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -pedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -O3 $(INCLUDES) $(COMPONENTS) $(PIECES) $(BOARD) $(MAIN)
board:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(BOARD) $(MAIN) $(STD)
pieces:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(PIECES) $(MAIN) $(STD)
