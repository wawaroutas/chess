#include "knight.h"   // Knight

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position

Knight::Knight(Position initPostion, Color color)
    : Material(initPostion, color, 3) {}

//Returns an std::vector<Position> with all available positions a Knight piece
//can attack/move
std::vector<Position>
Knight::AvailableMoves(const std::vector<Material*>& enemy) const {
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    Position possible_position = position_ + move;
    if (PositionValid(possible_position, enemy, color_)) {
      available.push_back(possible_position);
    }
  }
  return available;
}

int Knight::value() const noexcept {
  return 3;
}

std::vector<Position> Knight::AvailableAttacks(const std::vector<Material*>& enemy) const
{
  return AvailableMoves(enemy);
}
