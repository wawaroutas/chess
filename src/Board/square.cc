#include "square.h"
#include "color.h"
#include "location.h"
#include "piece.h"
#include <iostream>

Square::Square()
    : location_(BoardFile::A, 1), color_(Color::kWhite), piece_(nullptr) {}

Square::Square(Location location, Color color, Piece* piece)
    : location_(location), color_(color), piece_(piece) {}

bool Square::operator==(const Square& other) {
  return other.GetLocation() == location_ && other.GetColor() == color_;
}

std::ostream& operator<<(std::ostream& os, Square& square) {
   os << "Square: " << square.location_ << "\nColor: " << square.color_
    << "\nPiece:" << square.GetPiece();
   return os;
}
//------Getters-----//
Location Square::GetLocation() const{return location_;}
Color Square::GetColor() const{return color_;}
Piece* Square::GetPiece(){return piece_;}
bool Square::Occupied(){  return piece_==nullptr;}
