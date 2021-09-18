#ifndef CHESS_SRC_PIECES_BISHOP_H
#define CHESS_SRC_PIECES_BISHOP_H

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


class Bishop : public Material {
 public:
  Bishop(std::pair<int, int> initPostion, Color color);
  std::vector<std::pair<int, int>>
  CheckAvailableMoves(std::vector<Material*> enemy) override;
};

#endif // CHESS_SRC_PIECES_BISHOP_H