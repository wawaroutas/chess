#ifndef CHESS_SRC_PIECES_BISHOP_H
#define CHESS_SRC_PIECES_BISHOP_H

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


class Bishop : public Material {
 public:
  Bishop(Position initPostion, Color color);
  std::vector<Position>
  CheckAvailableMoves(const std::vector<Material*>& enemy) override;
  int value() const noexcept override;
};

#endif // CHESS_SRC_PIECES_BISHOP_H