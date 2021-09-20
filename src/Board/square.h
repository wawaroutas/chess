#ifndef CHESS_SRC_BOARD_SQUARE_H
#define CHESS_SRC_BOARD_SQUARE_H

#include "color.h"
#include "location.h"

class Square
{
private:
  Location location_;
  Color color_;
  Piece* piece;
  bool occupied_;
};


#endif // CHESS_SRC_BOARD_SQUARE_H
