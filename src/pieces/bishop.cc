#include "bishop.h"   // Bishop
#include <vector>     // std::vector
#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


Bishop::Bishop(Position initPostion, Color color)
    : Material(initPostion, color, 3) {}


//Returns an std::vector<Position> with all available positions a Bishop piece
//can attack/move
std::vector<Position>
Bishop::AvailableMoves(const std::vector<Material*>& enemy) const {
	std::vector<Position> available;
	Position tempPosition;
	int directions[2] = {-1, 1};
	for(int dirR : directions)
  {
		for(int dirC : directions)
    {
			tempPosition = position_;
      tempPosition.x += dirR;
      tempPosition.y += dirC;
      while(InBoard(tempPosition))
      {
          Color c;
          if(PositionOccupied(tempPosition,enemy,c))
          {
            if(GetColor()==c)
              break; //Occupied by ally then change direction
            else
            {
              available.push_back(tempPosition); //occupied by enemy then add it
              break;                             // and change direction
            }
          }
          else  //Not occupied at all
            available.push_back(tempPosition);
          tempPosition.x += dirR;
          tempPosition.y += dirC;
      }
		}
	}
	return available;
}

int Bishop::value() const noexcept {
  return 3;
}
