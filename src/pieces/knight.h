#ifndef CHESS_SRC_PIECES_KNIGHT_H
#define CHESS_SRC_PIECES_KNIGHT_H

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


class Knight : public Material {
 public:
  Knight(Position initPostion, Color color);
  std::vector<Position>
  AvailableMoves(const std::vector<Material*>& enemy) override;
  int value() const noexcept override;
};

#endif // CHESS_SRC_PIECES_KNIGHT_H