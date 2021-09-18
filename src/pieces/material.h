#ifndef CHESS_SRC_PIECES_MATERIAL_H
#define CHESS_SRC_PIECES_MATERIAL_H

#include <string>     // std::string
#include <vector>     // std::vector

#include "color.h"    // Color
#include "position.h" // Position

class Material {
 public:
  Material(Position initPostion, Color color, int points);
  bool MoveMaterial(Position newPosition,
                    const std::vector<Material*>& enemy);
  virtual std::vector<Position>
  CheckAvailableMoves(const std::vector<Material*>& enemy) = 0;
  //-----------Getters&Setters--------
  std::string GetColor();
  std::pair<int,int> GetPosition();
  int GetPoints();
 protected:
  bool InBoard(std::pair<int,int> pos);
  const Color color_;
  Position position_;
  int points_;
};

#endif // CHESS_SRC_PIECES_MATERIAL_H
