#include <cstdlib>    // EXIT_SUCCESS
#include <iostream>   // std::cout
#include <vector>     // std::vector

#include "chesspieces.h"   // King, Queen, Rook, Knight, Bishop, Pawn
#include "color.h"    // Color
#include "position.h" // Position
#include "location.h"
#include "square.h"
int main() {
	Location loc(BoardFile::A,2);
	Square sq(loc,Color::kBlack,nullptr);
	std::cout<< BoardFile::A << '\n';
  std::cout << Color::kBlack << std::endl;
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
