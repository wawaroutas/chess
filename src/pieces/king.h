#ifndef CHESS_SRC_PIECES_KING_H
#define CHESS_SRC_PIECES_KING_H

#include "position.h"    // Position
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


class King : public Material {
 public:
  King(Position initPostion, Color color);
  std::vector<Position>
  CheckAvailableMoves(const std::vector<Material*>& enemy) override;
  int value() const noexcept override;
};

#endif // CHESS_SRC_PIECES_KING_H