#include "knight.h"   // Knight

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square

Knight::Knight(Position initPostion, Color color)
    : Piece(initPostion, color, 3) {}


int Knight::value() const noexcept {
  return 3;
}

void Knight::Print(std::ostream& os) const noexcept {
  os << 'N';
}


//Returns an std::vector<Position> with all available positions a Knight piece
//can attack/move
std::vector<Position> Knight::AvailableMoves(Board<8,8> board) const
{
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    if((position_+move).InBoard()){
        Square square = board.square(position_ + move);
        if(canMove(square))
          available.push_back(position_+move);
    }
  }
  return available;
}
