all:
	g++ -Isrc/pieces -Isrc -o Chess ./src/*.cc ./src/pieces/*.cc -std=c++17
