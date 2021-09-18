#ifndef CHESS_SRC_PIECES_BISHOP_H
#define CHESS_SRC_PIECES_BISHOP_H

#include "position.h"    // Position
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


class Bishop : public Material {
 public:
  Bishop(Position initPostion, Color color);
  std::vector<Position>
  CheckAvailableMoves(const std::vector<Material*>& enemy) override;
};

#endif // CHESS_SRC_PIECES_BISHOP_H