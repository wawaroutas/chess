#ifndef CHESS_SRC_PIECES_PAWN_H
#define CHESS_SRC_PIECES_PAWN_H

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


class Pawn : public Material {
 public:
  Pawn(std::pair<int, int> initPostion, Color color);
  std::vector<std::pair<int, int>>
  CheckAvailableMoves(std::vector<Material*> enemy) override;
};

#endif // CHESS_SRC_PIECES_PAWN_H