#include "king.h"     // King

#include <limits>     // std::numeric_limits
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


King::King(Position initPostion, Color color)
    : Material(initPostion, color, 1000) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<Position>
King::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<Position> available;
	Position tempPosition;

	return available;
}

int King::value() const noexcept {
  return std::numeric_limits<int>::max();
}