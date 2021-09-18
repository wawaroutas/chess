#include "king.h"     // King

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position

King::King(Position initPostion, Color color)
    : Material(initPostion, color, 1000) {}

//TODO: Refactor & cleanup
//TODO: Add piece collision
std::vector<Position>
King::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<Position> available;
	Position tempPosition;
  //Up&down movement
  for(int dir : {-1,1})
  {
    tempPosition = position_;
    tempPosition.x+=dir;
    if(InBoard(tempPosition))
      available.push_back(tempPosition);
    else
      break;
  }
  //Left&right movement
  for(int dir : {-1,1})
  {
    tempPosition = position_;
    tempPosition.y+=dir;
    if(InBoard(tempPosition))
      available.push_back(tempPosition);
    else
      break;
  }
  //Diagonal movement
  for(int dirR : {-1,1}) {
		for(int dirC : {-1,1}) {
    tempPosition = position_;
    tempPosition.x+=dirR;
    tempPosition.y+=dirC;
    if(InBoard(tempPosition))
      available.push_back(tempPosition);
    else
      break;
  }
}
	return available;
}
