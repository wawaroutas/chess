#ifndef CHESS_SRC_PIECES_QUUEN_H
#define CHESS_SRC_PIECES_QUEEN_H

#include "position.h"    // Position
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


class Queen : public Material {
 public:
  Queen(Position initPostion, Color color);
  std::vector<Position>
  CheckAvailableMoves(const std::vector<Material*>& enemy) override;
};

#endif // CHESS_SRC_PIECES_QUEEN_H