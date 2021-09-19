#ifndef CHESS_SRC_PIECES_KING_H
#define CHESS_SRC_PIECES_KING_H

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


class King : public Material {
 public:
  King(Position initPostion, Color color);
  std::vector<Position>
  AvailableMoves(const std::vector<Material*>& enemy) const override;
  int value() const noexcept override;
};

#endif // CHESS_SRC_PIECES_KING_H