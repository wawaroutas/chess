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
  Color GetColor() const noexcept;
  Position GetPosition() const noexcept;
  //Change later
  virtual int value() const noexcept = 0;
 protected:
  bool InBoard(Position pos);
  const Color color_;
  Position position_;
  int points_;
};
//Helpful for finding if a position is occupied by another piece in the board
//Returns true if it is occupied,false if it is free
bool PositionOccupied(Position pos,const std::vector<Material*>& enemy,Color&);

#endif // CHESS_SRC_PIECES_MATERIAL_H
