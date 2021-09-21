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
Pawn::AvailableMoves(const std::vector<Piece*>& enemy) const {
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

std::vector<Position> Pawn::AvailableAttacks(const std::vector<Piece*>& enemy) const
{
    std::vector<Position> attacks;
    Position possible_position1 = position_ + Position{-1,1};
    Position possible_position2 = position_ + Position{1,1};
    for(Piece* piece : enemy)
    {
      if(possible_position1 == piece->GetPosition() && color_ != piece->GetColor())
        attacks.push_back(possible_position1);
      if(possible_position2 == piece->GetPosition() && color_ != piece->GetColor())
        attacks.push_back(possible_position2);
    }
    return attacks;
}

std::vector<Position> Pawn::test(Board board) const
{
  
	std::vector<Position> available;

  return available;

}
