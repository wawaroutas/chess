#include "queen.h"    // Queen

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


Queen::Queen(Position initPostion, Color color)
    : Material(initPostion, color, 9) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<Position>
Queen::AvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<Position > available;
	Position tempPosition;
	// first = row / second = column
	int directions[2] = {-1, 1};
  for(int dir : directions) //up and down movement
  {
  	tempPosition = position_;
    tempPosition.x += dir;
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
        tempPosition.x+=dir;
    }
	}
  for(int dir : directions) //Left and right movement
  {
    tempPosition = position_;
    tempPosition.y += dir;
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
        tempPosition.y+=dir;
    }
  }
	//diagonal
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

int Queen::value() const noexcept {
  return 9;
}
