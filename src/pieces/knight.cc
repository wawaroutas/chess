#include "knight.h"   // Knight

#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h" // Piece
#include "position.h" // Position
#include "square.h"
#include "board.h"
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

std::vector<Position> Knight::AvailableAttacks(const std::vector<Piece*>& enemy) const
{
  return AvailableMoves(enemy);
}

std::vector<Position> Knight::test(Board<8,8> board) const
{
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    if((position_+move).InBoard()){
      Position temp = position_ + move;
      // Square square = board.square(temp);
      // if(!square.Occupied())
      //   available.push_back(position_+move);
    }
  }
  return available;
}
