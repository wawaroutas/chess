#include "square.h"   // Square

#include <ostream>    // std::ostream

#include "color.h"    // Color
#include "position.h" // Position
#include "piece.h"    // Piece


Square::Square()
    : position_({0, 0}), color_(Color::kWhite), piece_(nullptr) {}

Square::Square(Position position, Color color, Piece* piece)
    : position_(position), color_(color), piece_(piece) {}

bool Square::operator==(const Square& other) {
  return other.GetPosition() == position_ && other.GetColor() == color_;
}

std::ostream& operator<<(std::ostream& os, const Square& square) {
   if (square.piece_ == nullptr) {
     if (square.color_ == Color::kWhite) {
       os << static_cast<char>(176); // '▓'
     } else {
       os << static_cast<char>(178); // '░'
     }
   } else {
     os << square.piece_;
   }
   return os;
}
//------Getters-----//
Position Square::GetPosition() const { return position_; }
Color Square::GetColor() const { return color_; }
Piece* Square::GetPiece() const { return piece_; }
bool Square::Occupied() const { return piece_ == nullptr; }

//--------Setters-----------//
void Square::SetPosition(int x, int y) {
  position_.x = x;
  position_.y = y;
}
void Square::SetPiece(Piece* piece) {
  piece_ = piece;
}
void Square::SetColor(const Color color) {
  color_ = color;
}
