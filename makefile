all:
	g++ -Isrc/pieces -Isrc -o Chess ./src/*.cc ./src/pieces/*.cc -std=c++17
alex:
	g++ -std=c++17 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -pedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -O3 -Isrc/pieces -Isrc ./src/*.cc ./src/pieces/*.cc

