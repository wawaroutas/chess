#ifndef CHESS_SRC_PIECES_MATERIAL_H
#define CHESS_SRC_PIECES_MATERIAL_H

#include <string>     // std::string
#include <vector>     // std::vector

#include "color.h"    // Color
#include "position.h" // Position
class Material {
 public:
  Material(Position initPostion, Color color, int points);
  bool MoveMaterial(Position newPosition, const std::vector<Material*>& enemy);
  virtual std::vector<Position>
  AvailableMoves(const std::vector<Material*>& enemy) = 0;
  //-----------Getters&Setters--------
  std::string GetColor();
  Position GetPosition();
  //Change later
  bool PositionOccupied(const std::vector<Material*> enemy);
  virtual int value() const noexcept = 0;
 protected:
  bool InBoard(Position pos);
  const Color color_;
  Position position_;
  int points_;
};

#endif // CHESS_SRC_PIECES_MATERIAL_H
