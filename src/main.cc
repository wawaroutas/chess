#include <cstdlib>    // EXIT_SUCCESS
#include <iostream>   // std::cout
#include <vector>     // std::vector

#include "pieces.h"   // King, Queen, Rook, Knight, Bishop, Pawn
#include "color.h"    // Color
#include "position.h" // Position


int main() {

	Bishop kn({4,7}, Color::kWhite);
	Bishop kn1({3,6}, Color::kWhite);
	Bishop kn2({5,6}, Color::kBlack);
	std::vector<Material*> v;
	 v.push_back(&kn2);
	 v.push_back(&kn1);
	auto yo = kn.AvailableMoves(v);
	for (auto& [x, y] : yo) {
		std::cout << '(' << x << ',' << y << ")\n";
	}
	return EXIT_SUCCESS;
}
