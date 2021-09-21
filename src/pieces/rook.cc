#include "rook.h"     // Rook

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square

Rook::Rook(Position initPostion, Color color)
    : Piece(initPostion, color, 5) {} // TODO: make points static const int


//Returns an std::vector<Position> with all available positions a Rook piece
//can capture/move
std::vector<Position> Rook::AvailableMoves(Board& board) const {
  static const int kMovableDirections = 4;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {0, -1}, {-1, 0}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    while((position_+move).InBoard()){
      if(canMove(board.square(position_+move)))
        available.push_back(position_+move);
      if(!board.square(position_+move).Occupied())
        move+=move;
      else
        break; //Square occupied so move to another direction
    }
  }
  return available;
}

int Rook::value() const noexcept {
  return 5;
}

void Rook::Print(std::ostream& os) const noexcept {
  os << 'R';
}
