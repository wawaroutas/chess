#include "queen.h"    // Queen

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


Queen::Queen(Position initPostion, Color color)
    : Material(initPostion, color, 9) {}

//Returns an std::vector<Position> with all available positions a Queen piece
//can attack/move
std::vector<Position>
Queen::AvailableMoves(const std::vector<Material*>& enemy) const {
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Position> available;
  for (int i = 0; i < kMovableDirections; ++i) {
    Position possible_position = position_;
    while (IsValid(possible_position += moves[i], enemy)) {
      available.push_back(possible_position);
    }
  }
  
	// Position tempPosition;
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
	// //diagonal
	// for(int dirR : directions)
  // {
	// 	for(int dirC : directions)
  //   {
	// 		tempPosition = position_;
  //     tempPosition.x += dirR;
  //     tempPosition.y += dirC;
  //     while(InBoard(tempPosition))
  //     {
  //         Color c;
  //         if(PositionOccupied(tempPosition,enemy,c))
  //         {
  //           if(GetColor()==c)
  //             break; //Occupied by ally then change direction
  //           else
  //           {
  //             available.push_back(tempPosition); //occupied by enemy then add it
  //             break;                             // and change direction
  //           }
  //         }
  //         else  //Not occupied at all
  //           available.push_back(tempPosition);
  //         tempPosition.x += dirR;
  //         tempPosition.y += dirC;
  //     }
	// 	}
  // }
	// return available;
}

int Queen::value() const noexcept {
  return 9;
}
