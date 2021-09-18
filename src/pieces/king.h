#ifndef CHESS_SRC_PIECES_KING_H
#define CHESS_SRC_PIECES_KING_H

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


class King : public Material {
 public:
  King(std::pair<int, int> initPostion, Color color);
  std::vector<std::pair<int, int>>
  CheckAvailableMoves(const std::vector<Material*>& enemy) override;
};

#endif // CHESS_SRC_PIECES_KING_H