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
  AvailableMoves(const std::vector<Material*>& enemy) const override;
  std::vector<Position>
  AvailableAttacks(const std::vector<Material*>& enemy) const override;
  int value() const noexcept override;
private:
  bool firstMove_;
};

#endif // CHESS_SRC_PIECES_PAWN_H
