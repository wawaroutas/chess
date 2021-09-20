#include "square.h"   // Square

#include <ostream>    // std::ostream

#include "color.h"    // Color
#include "position.h" // Position
#include "piece.h"    // Piece


Square::Square()
    : position_(BoardFile::A, 1), color_(Color::kWhite), piece_(nullptr) {}

Square::Square(Position location, Color color, Piece* piece)
    : position_(location), color_(color), piece_(piece) {}

bool Square::operator==(const Square& other) {
  return other.GetLocation() == position_ && other.GetColor() == color_;
}

std::ostream& operator<<(std::ostream& os, Square& square) {
   os << "Square: " << square.position_ << "\nColor: " << square.color_
    << "\nPiece:" << square.GetPiece();
   return os;
}
//------Getters-----//
Position Square::GetLocation() const{return position_;}
Color Square::GetColor() const{return color_;}
Piece* Square::GetPiece(){return piece_;}
bool Square::Occupied(){  return piece_==nullptr;}

void Square::SetColor(const Color color) {
  color_ = color;
}
