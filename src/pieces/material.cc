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
	std::vector<Position> available = CheckAvailableMoves(enemy);
	if (std::find(std::begin(available),
                std::end(available),
                newPosition) != std::end(available)) {
		position_ = newPosition;
		return true;
	}
	return false;
}

bool Material::InBoard(std::pair<int,int> pos) {
	return pos.first <= 8 && pos.first > 0 && pos.second <= 8 && pos.second > 0;
}
