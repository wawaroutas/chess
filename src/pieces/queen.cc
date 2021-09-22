#include "queen.h"    // Queen

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square


Queen::Queen(Position initPostion, Color color)
    : Piece(initPostion, color, 9) {}

//Returns an std::vector<Square> with all available positions a Queen piece
//can capture/move
std::vector<Square> Queen::AvailableMoves(Board& board) const {
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Square> available;
  for (Position move : moves) {
    while((position_+move).InBoard()){
      Square square = board.square(position_+move);
      if(canMove(square))
        available.push_back(square);
      if(!square.Occupied())
        move+=move;
      else
        break; //Square occupied so move to another direction
    }
  }
  return available;
}

int Queen::value() const noexcept {
  return 9;
}

void Queen::Print(std::ostream& os) const noexcept {
  os << 'Q';
}
