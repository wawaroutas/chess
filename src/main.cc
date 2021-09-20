#include <cstdlib>    // EXIT_SUCCESS
#include <iostream>   // std::cout
#include <vector>     // std::vector

#include "chesspieces.h"   // King, Queen, Rook, Knight, Bishop, Pawn
#include "color.h"    // Color
#include "position.h" // Position
#include "Position.h"
#include "square.h"
int main() {
	Position a(0,0), b(7,7);
	std::cout << "a(0,0):" << a << ' ' << b;
	// Bishop kn({4,7}, Color::kWhite);
	// Bishop kn1({3,6}, Color::kWhite);
	// Bishop kn2({5,6}, Color::kBlack);
	// std::vector<Piece*> v;
	//  v.push_back(&kn2);
	//  v.push_back(&kn1);
	// auto yo = kn.AvailableMoves(v);
	// for (auto& [x, y] : yo) {
	// 	std::cout << '(' << x << ',' << y << ")\n";
	// }
	return EXIT_SUCCESS;
}
