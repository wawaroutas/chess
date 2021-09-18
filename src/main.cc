#include <cstdlib>    // EXIT_SUCCESS
#include <iostream>   // std::cout
#include <vector>     // std::vector

#include "pieces.h"   // King, Queen, Rook, Knight, Bishop, Pawn 
#include "color.h"    // Color
#include "position.h" // Position


int main() {
	Position p = {4, 4};
	Knight kn(p, Color::kBlack);
	std::vector<Material*> v;
	auto yo = kn.CheckAvailableMoves(v);
	for (auto& [x, y] : yo) {
		std::cout << '(' << x << ',' << y << ")\n";
	}
	return EXIT_SUCCESS;
}
