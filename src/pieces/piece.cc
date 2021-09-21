#include "piece.h" // Piece

#include <algorithm>  // std::find()
#include <ostream>    // std::ostream
#include <string>     // std::string
#include <vector>     // std::vector

#include "color.h"    // Color
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square

Piece::Piece(Position initPostion, Color color, int points)
    : position_(initPostion), color_(color),points_(points) {}

// bool Piece::MovePiece(Position newPosition,
//                             const std::vector<Piece*>& enemy) {
// 	std::vector<Position> available = AvailableMoves(enemy);
// 	if (std::find(std::begin(available),
//                 std::end(available),
//                 newPosition) != std::end(available)) {
// 		position_ = newPosition;
// 		return true;
// 	}
// 	return false;
// }

Position Piece::GetPosition() const noexcept {
  return position_;
}

Color Piece::GetColor() const noexcept {
  return color_;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
  piece.Print(os);
  return os;
}
bool Piece::canMove(Square& target) const
{
  if(!target.Occupied()) return true;
  if(target.GetPiece()->GetColor() == color_)
    return false;
  return true; //Occupied && different color
}

std::vector<Position> Piece::AvailableCaptures(Board<8,8> board) const{
  std::vector<Position> attacks;
  for(Position pos : AvailableMoves(board))
  {
    Square square = board.square(pos);
    if(square.Occupied())
      if(square.GetPiece()->GetColor()!=color_)
        attacks.push_back(pos);
  }
  return attacks;
}
