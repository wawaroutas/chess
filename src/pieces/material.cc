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

Position Material::GetPosition() const noexcept {
  return position_;
}

Color Material::GetColor() const noexcept {
  return color_;
}

//Returns true if a position is occupied by a piece in enemy list and stores its
//color in c variable
bool PositionValid(Position pos, const std::vector<Material*>& enemy, Color& color) {
  if(!pos.InBoard()) return false;
  for(Material* piece : enemy)
  {
    if(pos == piece->GetPosition() && color == piece->GetColor())
      return false;
  }
  return true;
}
