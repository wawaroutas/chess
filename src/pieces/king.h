#ifndef CHESS_SRC_PIECES_KING_H
#define CHESS_SRC_PIECES_KING_H

#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h" // Piece
#include "position.h" // Position


class King : public Piece {
 public:
  King(Position initPostion, Color color);
  std::vector<Position>
  AvailableMoves(const std::vector<Piece*>& enemy) const override;
  std::vector<Position>
  AvailableAttacks(const std::vector<Piece*>& enemy) const override;
  int value() const noexcept override;
};

#endif // CHESS_SRC_PIECES_KING_H
