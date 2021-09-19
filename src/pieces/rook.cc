#include "rook.h"     // Rook
#include <vector>     // std::vector
#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


Rook::Rook(Position initPostion, Color color)
    : Material(initPostion, color, 5) {} // TODO: make points static const int

//Method that returns all available moves that a Rook can make,including other
//piece collision and ally collision
std::vector<Position>
Rook::AvailableMoves(const std::vector<Material*>& enemy) const {
	std::vector<Position> available;
	Position tempPosition;
	int directions[2] = {-1, 1};
	for(int dir : directions) //up and down movement
  {
  	tempPosition = position_;
    tempPosition.x += dir;
		while(tempPosition.InBoard())
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
    while(tempPosition.InBoard())
    {
      if(InBoard(position_+move))
      {
          available.push_back(position_+move);
          Color c;
          if(PositionOccupied(position_,enemy,c) && c == GetColor()) //same color
          {
            available.pop_back();
            break;
          }else
          {
            move+=move;
          }
      }
    }
  }
	// int directions[2] = {-1, 1};
	// for(int dir : directions) //up and down movement
  // {
  // 	tempPosition = position_;
  //   tempPosition.x += dir;
	// 	while(InBoard(tempPosition))
  //   {
  //     Color c;
  //     if(PositionOccupied(tempPosition,enemy,c))
  //     {
  //       if(GetColor()==c)
  //         break; //Occupied by ally then change direction
  //       else
  //       {
  //         available.push_back(tempPosition); //occupied by enemy then add it
  //         break;                             // and change direction
  //       }
  //     }
  //     else  //Not occupied at all
  //       available.push_back(tempPosition);
  //       tempPosition.x+=dir;
  //   }
	// }
  // for(int dir : directions) //Left and right movement
  // {
  //   tempPosition = position_;
  //   tempPosition.y += dir;
  //   while(InBoard(tempPosition))
  //   {
  //     Color c;
  //     if(PositionOccupied(tempPosition,enemy,c))
  //     {
  //       if(GetColor()==c)
  //         break; //Occupied by ally then change direction
  //       else
  //       {
  //         available.push_back(tempPosition); //occupied by enemy then add it
  //         break;                             // and change direction
  //       }
  //     }
  //     else  //Not occupied at all
  //       available.push_back(tempPosition);
  //       tempPosition.y+=dir;
  //   }
  // }
	return available;
}

int Rook::value() const noexcept {
  return 5;
}
