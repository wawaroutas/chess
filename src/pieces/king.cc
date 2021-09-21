#include "king.h"     // King

#include <algorithm>  // std::find(), std::remove_if()
#include <limits>     // std::numeric_limits
#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position


King::King(Position initPostion, Color color)
    : Piece(initPostion, color, 1000) {}

//TODO: Refactor & cleanup
//TODO: Add piece collision
std::vector<Position>
King::AvailableMoves(Board<8,8> board) const {
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    Position possible_position = position_ + move;

  }
  return available;
}

int King::value() const noexcept {
  return std::numeric_limits<int>::max();
}

void King::Print(std::ostream& os) const noexcept {
  os << 'K';
}

std::vector<Position> King::AvailableAttacks(const std::vector<Piece*>& enemy) const
{
  //return AvailableMoves(enemy);
}
