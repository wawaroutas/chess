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
<<<<<<< HEAD
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
=======
  static const int kMovableDirections = 4;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {0, -1}, {-1, 0}
  };
	std::vector<Position> available;
  for (Position move : moves) {
    Position possible_position = position_;
    while (PositionValid(possible_position += move, enemy, color_)) {
      available.push_back(possible_position);
>>>>>>> fd5fef0469de4a56fa7611e241b4e7ae60fb8f86
    }
  }
  return available;
}

int Rook::value() const noexcept {
  return 5;
}
