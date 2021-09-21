#include "pawn.h"     // Pawn

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position


Pawn::Pawn(Position initPostion,Color color)
    : Piece(initPostion, color, 1),firstMove_(true) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<Position>
Pawn::AvailableMoves(Board<8,8> board) const {
	std::vector<Position> available;
  // if(firstMove_){
  //   Position moves[] = {0,2};
  //   firstMove_ = false;
  // }
  // else
  //   Position moves[] = {0,1};
  //
  // for(Position move : moves)
  // {
  //   Position possible_position = position_ + move;
  //   if(PositionValid(possible_position,enemy,color_))
  //     available.push_back(possible_position);
  // }
	return available;
}

int Pawn::value() const noexcept {
  return 1;
}

void Pawn::Print(std::ostream& os) const noexcept {
  os << 'P';
}
