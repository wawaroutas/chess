#include "pawn.h"     // Pawn

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square

Pawn::Pawn(Position initPostion,Color color)
    : Piece(initPostion, color, 1),firstMove_(true) {}

//Returns an std::vector<Position> with all available positions a Pawn piece
//can capture/move
//TODO: Add en pessant
std::vector<Position> Pawn::AvailableMoves(Board& board) const {
	std::vector<Position> available;
  Position move = {};
  if(firstMove_){
     move = {0,2};
     // firstMove_ = false;
  }
  else{
     move = {0,1};
  }
  Position captures[] = {{1,1},{-1,1}};
  if((position_+move).InBoard())
  {
    if(!board.square(position_+move).Occupied()){
      available.push_back(position_+move);
    }
  }

  for(Position capture : captures)
  {
    if((position_+capture).InBoard()){
      if(board.square(position_+capture).Occupied())
        if(board.square(position_+capture).GetPiece()->GetColor() != color_)
          available.push_back(position_+capture);
    }
  }
  return available;
}

bool Pawn::MovePiece(Position newPosition,Board board) {
  if(Piece::MovePiece(newPosition,board)){
    firstMove_ = false;
    return true;
  }
  return false;
}


int Pawn::value() const noexcept {
  return 1;
}

void Pawn::Print(std::ostream& os) const noexcept {
  os << 'P';
}
