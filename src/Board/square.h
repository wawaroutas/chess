#ifndef CHESS_SRC_BOARD_SQUARE_H
#define CHESS_SRC_BOARD_SQUARE_H

#include "color.h"
#include "location.h"
#include "piece.h"
#include <iostream>

class Square
{
private:
  const Location location_;
  const Color color_;
  Piece* piece_;
public:
  Square(Location location,Color color,Piece* piece);
  Location GetLocation() const;
  Color GetColor() const;
  Piece* GetPiece();
  bool Occupied();
  bool operator==(const Square& other);
  friend std::ostream& operator<<(std::ostream&, Square&);
};



#endif // CHESS_SRC_BOARD_SQUARE_H
