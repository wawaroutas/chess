#ifndef CHESS_SRC_PIECES_BISHOP_H
#define CHESS_SRC_PIECES_BISHOP_H

#include <vector>     // std::vector
#include "color.h"    // Color
#include "piece.h" // Piece
#include "position.h" // Position


class Bishop : public Piece {
 public:
  Bishop(Position initPostion, Color color);
  std::vector<Position>
  AvailableMoves(const std::vector<Piece*>& enemy) const override;
  std::vector<Position>
  AvailableAttacks(const std::vector<Piece*>& enemy) const override;
  int value() const noexcept override;
};

#endif // CHESS_SRC_PIECES_BISHOP_H
