#include "queen.h"    // Queen

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


Queen::Queen(Position initPostion, Color color)
    : Material(initPostion, color, 9) {}

//Returns an std::vector<Position> with all available positions a Queen piece
//can attack/move
std::vector<Position>
Queen::AvailableMoves(const std::vector<Material*>& enemy) const {
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    Position possible_position = position_;
    while (PositionValid(possible_position += move, enemy, color_)) {
      available.push_back(possible_position);
    }
  }
  return available;
}

int Queen::value() const noexcept {
  return 9;
}
