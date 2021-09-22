#Variables
CC = g++
INCLUDES = -Isrc/components -Isrc/board -Isrc/pieces -Isrc -Isrc/application
OUTPUT = -o Chess
BOARD = ./src/board/*.cc
PIECES = ./src/pieces/*.cc
COMPONENTS = ./src/components/*.cc
APPLICATION = ./src/application/*.cc
MAIN = ./src/main.cc
STD = -std=c++17
OPTIMIZATION = -O3
WARNINGS = -Wall -Wextra -Wshadow -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -pedantic -Wconversion -Wsign-conversion -Wmisleading-indentation

#Targets
#all compile and link the whole project
#board compile and link board and main
#pieces compile and link pieces
#alex make all but this weird guy added 15 flags
all:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(PIECES) $(BOARD) $(APPLICATION) $(MAIN) $(STD)
alex:
	$(CC) $(STD) $(WARNINGS) $(OPTIMIZATION) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(PIECES) $(BOARD) $(APPLICATION) $(MAIN)
board:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(BOARD) $(APPLICATION) $(MAIN) $(STD)
pieces:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(PIECES) $(APPLICATION) $(MAIN) $(STD)
