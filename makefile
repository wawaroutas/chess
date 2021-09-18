all:
	cls
	g++ -Isrc/pieces -Isrc -o Chess ./src/*.cc ./src/pieces/*.cc
