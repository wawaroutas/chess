#ifndef CHESS_SRC_PIECES_MATERIAL_H
#define CHESS_SRC_PIECES_MATERIAL_H

#include <string>  // std::string
#include <utility> // std::pair
#include <vector>  // std::vector

#include "color.h" // Color

class Material {
 public:
  Material(std::pair<int, int> initPostion, Color color, int points);
  bool MoveMaterial(std::pair<int, int> newPosition,
                    std::vector<Material*> enemy);
  virtual std::vector<std::pair<int, int>> 
  CheckAvailableMoves(std::vector<Material*> enemy) = 0;
  //-----------Getters&Setters--------
  std::string GetColor();
  std::pair<int,int> GetPosition();
  int GetPoints();
 protected:
  bool InBoard(std::pair<int,int> pos);
  const Color color_;
  std::pair<int, int> position_;
  int points_;
};

#endif // CHESS_SRC_PIECES_MATERIAL_H