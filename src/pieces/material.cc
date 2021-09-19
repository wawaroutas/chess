#include "material.h" // Material

#include <algorithm>  // std::find()
#include <string>     // std::string
#include <vector>     // std::vector

#include "color.h"    // Color
#include "position.h" // Position


Material::Material(Position initPostion, Color color, int points)
    : position_(initPostion), color_(color),points_(points) {}

bool Material::MoveMaterial(Position newPosition,
                            const std::vector<Material*>& enemy) {
	std::vector<Position> available = AvailableMoves(enemy);
	if (std::find(std::begin(available),
                std::end(available),
                newPosition) != std::end(available)) {
		position_ = newPosition;
		return true;
	}
	return false;
}

bool Material::InBoard(Position pos) {
	return pos.x <= 8 && pos.x > 0 && pos.y <= 8 && pos.y > 0;
}
Position Material::GetPosition()
{
  return position_;
}

Color Material::GetColor()
{
  return color_;
}

//Returns true if a position is occupied by a piece in enemy list and stores its
//color in c variable
bool PositionOccupied(Position pos,const std::vector<Material*> enemy,Color& color)
{
  for(Material* piece : enemy)
    if(piece->GetPosition() == pos)
    {
      color = piece->GetColor();
      return true;
    }
  return false;
}
