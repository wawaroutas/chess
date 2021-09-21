#ifndef CHESS_SRC_PIECES_PAWN_H
#define CHESS_SRC_PIECES_PAWN_H

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h"    // Position
#include "board.h"

class Pawn : public Piece {
 public:
  Pawn(Position initPostion, Color color);
  std::vector<Position>
  AvailableMoves(Board<8,8> board) const override;
  int value() const noexcept override;
 protected:
  void Print(std::ostream&) const noexcept override;
 private:
  bool firstMove_;
};

#endif // CHESS_SRC_PIECES_PAWN_H
