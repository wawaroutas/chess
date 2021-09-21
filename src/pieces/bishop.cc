#include "bishop.h"   // Bishop

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "Board.h"    // Board


Bishop::Bishop(Position initPostion, Color color)
    : Piece(initPostion, color, 3) {}

//Returns an std::vector<Position> with all available positions a Bishop piece
//can attack/move
std::vector<Position>
Bishop::AvailableMoves(Board<8,8> board) const {
  static const int kMovableDirections = 4;
  static const Position moves[kMovableDirections] = {
    {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    Position possible_position = position_;

  }
  return available;
}

int Bishop::value() const noexcept {
  return 3;
}

void Bishop::Print(std::ostream& os) const noexcept {
  os << 'B';
}

std::vector<Position>
Bishop::AvailableAttacks(const std::vector<Piece*>& enemy) const {
  ////return AvailableMoves(enemy);
}
