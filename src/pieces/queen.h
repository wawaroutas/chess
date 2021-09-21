#ifndef CHESS_SRC_PIECES_QUUEN_H
#define CHESS_SRC_PIECES_QUEEN_H

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board


class Queen : public Piece {
 public:
  Queen(Position initPostion, Color color);
  std::vector<Position> AvailableMoves(Board& board) const override;
  int value() const noexcept override;
 protected:
  void Print(std::ostream&) const noexcept override;
};

#endif // CHESS_SRC_PIECES_QUEEN_H
