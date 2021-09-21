#include "bishop.h"   // Bishop

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square


Bishop::Bishop(Position initPostion, Color color)
    : Piece(initPostion, color, 3) {}

//Returns an std::vector<Position> with all available positions a Bishop piece
//can attack/move
std::vector<Position>
Bishop::AvailableMoves(Board board) const {
  static const int kMovableDirections = 4;
  static const Position moves[kMovableDirections] = {
    {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    while((position_+move).InBoard())
    {
      Square square = board.square(position_+move);
      if(canMove(square))
        available.push_back(position_+move);
      if(!square.Occupied())
        move+=move;
      else
        break; //Square occupied so move to another direction
    }
  }
  return available;
}

int Bishop::value() const noexcept {
  return 3;
}

void Bishop::Print(std::ostream& os) const noexcept {
  os << 'B';
}
