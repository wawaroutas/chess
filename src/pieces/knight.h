#ifndef CHESS_SRC_PIECES_KNIGHT_H
#define CHESS_SRC_PIECES_KNIGHT_H

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board

class Knight : public Piece {
 public:
  Knight(Position initPostion, Color color);
  std::vector<Position> AvailableMoves(Board& board) const override;
  int value() const noexcept override;
 protected:
  void Print(std::ostream&) const noexcept override;
};

#endif // CHESS_SRC_PIECES_KNIGHT_H
