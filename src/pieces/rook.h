#ifndef CHESS_SRC_PIECES_ROOK_H
#define CHESS_SRC_PIECES_ROOK_H

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


class Rook : public Material {
 public:
  Rook(Position initPostion, Color color);
  std::vector<Position> 
  AvailableMoves(const std::vector<Material*>& enemy) override;
  int value() const noexcept override;
};

#endif // CHESS_SRC_PIECES_ROOK_H