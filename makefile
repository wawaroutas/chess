#Use make Chess and make clean to clean up. Make all stays for debug
#After Make clean use make Chessbinaries 

#Variables
CC = g++
INCLUDES =-Isrc/components -Isrc/board -Isrc/pieces -Isrc/application
OUTPUT = -o Chess
BOARD = ./src/board/*.cc
PIECES = ./src/pieces/*.cc
COMPONENTS = ./src/components/*.cc
APPLICATION = ./src/application/*.cc
MAIN = ./src/main.cc
STD = -std=c++17
OPTIMIZATION = -O3
WARNINGS = -Wall -Wextra -Wshadow -Wold-style-cast -Wcast-align \
-Wunused -Woverloaded-virtual -pedantic -Wconversion \
-Wsign-conversion -Wmisleading-indentation


all:
	$(CC) $(INCLUDES) $(OUTPUT) $(COMPONENTS) $(PIECES) $(BOARD)\
	 $(APPLICATION) $(MAIN) $(STD)

Chess: ./obj/main.o ./obj/board.o ./obj/player.o ./obj/chess.o ./obj/square.o ./obj/piece.o ./obj/position.o ./obj/pawn.o \
	./obj/rook.o ./obj/king.o ./obj/queen.o ./obj/bishop.o ./obj/knight.o
	$(CC) ./obj/main.o ./obj/board.o ./obj/player.o ./obj/chess.o ./obj/square.o ./obj/piece.o ./obj/position.o ./obj/pawn.o \
	./obj/rook.o ./obj/king.o ./obj/queen.o ./obj/bishop.o ./obj/knight.o $(OUTPUT)

Chessbinaries: main.o  board.o  player.o  chess.o  square.o  piece.o \
	position.o pawn.o rook.o king.o queen.o  bishop.o  knight.o
	$(CC) $^ ; mv *.o obj

main.o: src/main.cc
	$(CC) $(INCLUDES) -c ./src/main.cc

position.o: ./src/components/position.cc ./src/components/position.h
	$(CC) $(INCLUDES) -c ./src/components/position.cc

piece.o: ./src/pieces/piece.cc ./src/pieces/piece.h ./src/components/color.h \
	./src/components/position.h
	$(CC) $(INCLUDES) -c ./src/pieces/piece.cc

rook.o: ./src/pieces/rook.cc ./src/pieces/rook.h ./src/pieces/piece.h
	$(CC) $(INCLUDES) -c ./src/pieces/rook.cc

queen.o: ./src/pieces/queen.cc ./src/pieces/queen.h ./src/pieces/piece.h
	$(CC) $(INCLUDES) -c ./src/pieces/queen.cc

pawn.o: ./src/pieces/pawn.cc ./src/pieces/pawn.h ./src/pieces/piece.h
	$(CC) $(INCLUDES) -c ./src/pieces/pawn.cc

knight.o: ./src/pieces/knight.cc ./src/pieces/knight.h ./src/pieces/piece.h
	$(CC) $(INCLUDES) -c ./src/pieces/knight.cc

king.o: ./src/pieces/king.cc ./src/pieces/king.h ./src/pieces/piece.h
	$(CC) $(INCLUDES) -c ./src/pieces/king.cc

bishop.o: ./src/pieces/bishop.cc ./src/pieces/bishop.h ./src/pieces/piece.h
	$(CC) $(INCLUDES) -c ./src/pieces/bishop.cc

square.o: ./src/board/square.cc ./src/board/square.h ./src/components/color.h \
	./src/components/position.h
	$(CC) $(INCLUDES) -c ./src/board/square.cc

board.o: ./src/board/board.cc ./src/board/board.h ./src/board/square.h \
	./src/components/position.h
	$(CC) $(INCLUDES) -c ./src/board/board.cc

player.o: ./src/application/player.cc ./src/application/player.h \
	./src/board/board.h ./src/pieces/piece.h
	$(CC) $(INCLUDES) -c ./src/application/player.cc

chess.o: ./src/application/chess.cc ./src/application/chess.h \
	./src/application/player.h ./src/board/board.h ./src/pieces/piece.h
	$(CC) $(INCLUDES) -c ./src/application/chess.cc
clean:
	rm ./obj/*.o
