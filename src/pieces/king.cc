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
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    Position possible_position = position_ + move;
<<<<<<< HEAD
    if (PositionValid(possible_position, enemy, color_)) {
      available.push_back(possible_position);
    }
=======
    if (PositionValid(possible_position,enemy,color_))
      available.push_back(possible_position);
>>>>>>> 1349eae995f68250bd32e961841b9b5e5ff8aed1
  }
  return available;
}

int King::value() const noexcept {
  return std::numeric_limits<int>::max();
}


std::vector<Position> King::AvailableAttacks(const std::vector<Material*>& enemy) const
{
  return AvailableMoves(enemy);
}
