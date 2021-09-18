#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // std::cout
#include <utility>  // std::pair
#include <vector>   // std::vector

#include "pieces.h" // King, Queen, Rook, Knight, Bishop, Pawn 
#include "color.h"  // Color


int main() {
	std::pair<int, int> p(4, 4);
	Knight kn(p, Color::kBlack);
	std::vector<Material*> v;
	auto yo = kn.CheckAvailableMoves(v);
	for (auto& [x, y] : yo) {
		std::cout << '(' << x << ',' << y << ")\n";
	}
	return EXIT_SUCCESS;
}
