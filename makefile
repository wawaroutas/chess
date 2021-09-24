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



#------------------------#
Chess: main.o board.o player.o chess.o
	$(CC) main.o board.o player.o chess.o $(OUTPUT)


main.o: main.cc board.h chess.h player.h chesspieces.h
	$(CC) $(INCLUDES) -c main.cc

position.o: position.cc position.h
	$(CC) $(INCLUDES) -c position.cc
	
piece.o: piece.cc piece.h color.h position.h
	$(CC) $(INCLUDES) -c piece.cc

rook.o: rook.cc rook.h piece.h
	$(CC) $(INCLUDES) -c rook.cc

queen.o: queen.cc queen.h piece.h
	$(CC) $(INCLUDES) -c queen.cc

pawn.o: pawn.cc pawn.h piece.h
	$(CC) $(INCLUDES) -c pawn.cc

knight.o: knight.cc knight.h piece.h
	$(CC) $(INCLUDES) -c knight.cc

king.o: king.cc king.h piece.h
	$(CC) $(INCLUDES) -c king.cc

bishop.o: bishop.cc bishop.h piece.h
	$(CC) $(INCLUDES) -c bishop.cc
square.o: square.cc square.h color.h position.h
	$(CC) $(INCLUDES) -c square.cc
board.o: board.cc board.h square.h position.h
	$(CC) $(INCLUDES) -c board.cc
player.o: player.cpp player.h board.h piece.h
	$(CC) $(INCLUDES) -c player.cc

chess.o: chess.cc chess.h player.h board.h piece.h
	$(CC) $(INCLUDES) -c chess.cc
