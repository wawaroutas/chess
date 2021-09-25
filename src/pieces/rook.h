#ifndef CHESS_SRC_PIECES_ROOK_H
#define CHESS_SRC_PIECES_ROOK_H

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board


class Rook : public Piece {
 public:
  Rook(Position initPostion, Color color);
  std::vector<Square> AvailableMoves(Board& board) const override;
  int value() const noexcept override;
  bool MovePiece(Square newSquare,Board& board) override;
 protected:
  void Print(std::ostream&) const noexcept override;
};

#endif // CHESS_SRC_PIECES_ROOK_H
