#ifndef CHESS_SRC_PIECES_PAWN_H
#define CHESS_SRC_PIECES_PAWN_H

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board

class Pawn : public Piece {
 public:
  Pawn(Position initPostion, Color color);
  std::vector<Position> AvailableMoves(Board board) const override;
  int value() const noexcept override;
  bool MovePiece(Position newPosition,Board board) override;
 protected:
  void Print(std::ostream&) const noexcept override;
 private:
  bool firstMove_;
};

#endif // CHESS_SRC_PIECES_PAWN_H
