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
Position Material::GetPosition() const noexcept {
  return position_;
}

Color Material::GetColor() const noexcept {
  return color_;
}
bool PositionOccupied(Position pos,const std::vector<Material*> enemy)
{
  for(Material* piece : enemy)
    if(piece->GetPosition() == pos)
      return true;
  return false;
}
