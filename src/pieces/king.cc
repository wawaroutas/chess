#include "king.h"     // King

#include <algorithm>  // std::find(), std::remove_if()
#include <limits>     // std::numeric_limits
#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "square.h"   // Square

King::King(Position initPostion, Color color)
    : Piece(initPostion, color, 1000) {}


//Returns an std::vector<Position> with all available positions a King piece
//can attack/move
//TODO add check 
std::vector<Position>
King::AvailableMoves(Board<8,8> board) const {
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    if((position_ + move).InBoard())
    {
      Square square = board.square(position_+move);
      if(canMove(square))
        available.push_back(position_ + move);
    }

  }
  return available;
}

int King::value() const noexcept {
  return std::numeric_limits<int>::max();
}

void King::Print(std::ostream& os) const noexcept {
  os << 'K';
}
