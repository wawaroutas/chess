#include "king.h"     // King

#include <algorithm>  // std::find(), std::remove_if()
#include <limits>     // std::numeric_limits
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


King::King(Position initPostion, Color color)
    : Material(initPostion, color, 1000) {}

//TODO: Refactor & cleanup
//TODO: Add piece collision
std::vector<Position>
King::AvailableMoves(const std::vector<Material*>& enemy) const {
  static const Position moves[] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    if (InBoard(position_ + move)) {
      available.push_back(position_ + move);
    }
  }
	return available;
}

int King::value() const noexcept {
  return std::numeric_limits<int>::max();
}