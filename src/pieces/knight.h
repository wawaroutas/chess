#ifndef CHESS_SRC_PIECES_KNIGHT_H
#define CHESS_SRC_PIECES_KNIGHT_H

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


class Knight : public Material {
 public:
  Knight(std::pair<int, int> initPostion, Color color);
  std::vector<std::pair<int, int>>
  CheckAvailableMoves(const std::vector<Material*>& enemy) override;
};

#endif // CHESS_SRC_PIECES_KNIGHT_H