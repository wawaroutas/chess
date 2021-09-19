#include <cstdlib>    // EXIT_SUCCESS
#include <iostream>   // std::cout
#include <vector>     // std::vector

#include "pieces.h"   // King, Queen, Rook, Knight, Bishop, Pawn
#include "color.h"    // Color
#include "position.h" // Position


int main() {
  King king({4, 4}, Color::kWhite); // a8
  std::vector<Material*> material;
  for (auto& [x, y] : king.AvailableMoves(material)) {
    std::cout << '(' << x << ',' << y << ")\n";
  }
  std::cout << "\n\n";
	Knight kn({4,4}, Color::kWhite);
	Bishop kn1({6,5}, Color::kWhite);
	Bishop kn2({3,2}, Color::kBlack);
	std::vector<Material*> v;
	 v.push_back(&kn2);
	 v.push_back(&kn1);
	auto yo = kn.AvailableMoves(v);
	for (auto& [x, y] : yo) {
		std::cout << '(' << x << ',' << y << ")\n";
	}
	return EXIT_SUCCESS;
}
