#ifndef CHESS_SRC_BOARD_SQUARE_H
#define CHESS_SRC_BOARD_SQUARE_H

#include <ostream>

#include "color.h"
#include "position.h"

class Piece; 

class Square {
 private:
  Position position_;
  Color color_;
  Piece* piece_;
 public:
  Square();
  Square(Position location, Color color, Piece* piece);
  Position GetLocation() const;
  Color GetColor() const;
  Piece* GetPiece();
  void SetColor(const Color);
  bool Occupied();
  bool operator==(const Square& other);
  friend std::ostream& operator<<(std::ostream&, Square&);
};

#endif // CHESS_SRC_BOARD_SQUARE_H
