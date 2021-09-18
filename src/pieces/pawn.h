#ifndef CHESS_SRC_PIECES_PAWN_H
#define CHESS_SRC_PIECES_PAWN_H

#include <vector>        // std::vector

#include "color.h"       // Color
#include "material.h"    // Material
#include "position.h"    // Position


class Pawn : public Material {
 public:
  Pawn(Position initPostion, Color color);
  std::vector<Position>
  CheckAvailableMoves(const std::vector<Material*>& enemy) override;
  int value() const noexcept override;
};

#endif // CHESS_SRC_PIECES_PAWN_H