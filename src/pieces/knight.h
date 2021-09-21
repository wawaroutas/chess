#ifndef CHESS_SRC_PIECES_KNIGHT_H
#define CHESS_SRC_PIECES_KNIGHT_H

#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h" // Piece
#include "position.h" // Position


class Knight : public Piece {
 public:
  Knight(Position initPostion, Color color);
  std::vector<Position>
  AvailableMoves(const std::vector<Piece*>& enemy) const override;
  std::vector<Position>
  AvailableAttacks(const std::vector<Piece*>& enemy) const override;
  int value() const noexcept override;
  std::vector<Position> test(Board<8,8> board) const;
};

#endif // CHESS_SRC_PIECES_KNIGHT_H
