#include "knight.h"   // Knight

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position

Knight::Knight(Position initPostion, Color color)
    : Material(initPostion, color, 3) {}

//Returns an std::vector<Position> with all available positions a Knight piece
//can attack/move
std::vector<Position>
Knight::AvailableMoves(const std::vector<Material*>& enemy) const {
	std::vector<Position> available;
  Position moves[] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
  Position tempPosition;
  for(Position move : moves){
    tempPosition = position_ + move;
    if(InBoard(tempPosition)){
      available.push_back(tempPosition);
      Color c;
      if(PositionOccupied(tempPosition,enemy,c) && c==GetColor()) //Ally occupied
        available.pop_back();              //If its occupied by an ally piece
    }                                    // remove the position from availables
  }
	return available;
}

int Knight::value() const noexcept {
  return 3;
}
