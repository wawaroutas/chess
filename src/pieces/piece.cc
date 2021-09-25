#include "piece.h" // Piece

#include <algorithm>  // std::find()
#include <memory>     // std::shared_ptr
#include <iostream>    // std::ostream
#include <string>     // std::string
#include <vector>     // std::vector

#include "color.h"    // Color
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square

Piece::Piece(Position initPostion, Color color, int points)
    : position_(initPostion), color_(color),points_(points)
    {}



std::ostream& operator<<(std::ostream& os, const Piece& piece) {
  piece.Print(os);
  return os;
}
bool Piece::canMove(Square& target) const {
  if(!target.Occupied()) return true;
  if(target.GetPiece()->GetColor() == color_)
    return false;
  return true; //Occupied && different color
}


std::vector<Square> Piece::AvailableCaptures(Board& board) const{
  std::vector<Square> attacks;
  for(Square square : AvailableMoves(board))
  {
    if(square.Occupied())
      if(square.GetPiece()->GetColor()!=color_)
        attacks.push_back(square);
  }
  return attacks;
}


//-------------Getters-------------//

Position Piece::GetPosition() const noexcept {return position_;}
Color Piece::GetColor() const noexcept {return color_;}
std::vector<Square> Piece::GetCurrentMoves() const noexcept{return currentMoves;}
