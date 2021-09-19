#include "rook.h"     // Rook
#include <vector>     // std::vector
#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


Rook::Rook(Position initPostion, Color color)
    : Material(initPostion, color, 5) {} // TODO: make points static const int

//Method that returns all available moves that a Rook can make,including other
//piece collision and ally collision
std::vector<Position>
Rook::AvailableMoves(const std::vector<Material*>& enemy) const {
  static const int kMovableDirections = 4;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {0, -1}, {-1, 0}
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

int Rook::value() const noexcept {
  return 5;
}
