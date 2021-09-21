#include "piece.h" // Piece

#include <algorithm>  // std::find()
#include <ostream>    // std::ostream
#include <string>     // std::string
#include <vector>     // std::vector

#include "color.h"    // Color
#include "position.h" // Position


Piece::Piece(Position initPostion, Color color, int points)
    : position_(initPostion), color_(color),points_(points) {}

bool Piece::MovePiece(Position newPosition,
                            const std::vector<Piece*>& enemy) {
	std::vector<Position> available = AvailableMoves(enemy);
	if (std::find(std::begin(available),
                std::end(available),
                newPosition) != std::end(available)) {
		position_ = newPosition;
		return true;
	}
	return false;
}

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

//Returns true if a position is occupied by a piece in enemy list and stores its
//color in c variable
bool PositionValid(Position pos, const std::vector<Piece*>& enemy, Color color) {
  if(!pos.InBoard()) return false;
  for(Piece* piece : enemy)
  {
    if(pos == piece->GetPosition() && color == piece->GetColor())
      return false;
  }
  return true;
}
