#include "knight.h"   // Knight

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h" // Piece
#include "position.h" // Position

Knight::Knight(Position initPostion, Color color)
    : Piece(initPostion, color, 3) {}

//Returns an std::vector<Position> with all available positions a Knight piece
//can attack/move
std::vector<Position>
Knight::AvailableMoves(const std::vector<Piece*>& enemy) const {
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

void Knight::Print(std::ostream& os) const noexcept {
  os << 'N';
}

std::vector<Position> Knight::AvailableAttacks(const std::vector<Piece*>& enemy) const
{
  return AvailableMoves(enemy);
}

template<int Files,int Ranks>
void Knight::move(Board<Files,Ranks> board){
    
}
