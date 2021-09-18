#include "material.h" // Material

#include <algorithm>  // std::find()
#include <string>     // std::string
#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color


Material::Material(std::pair<int, int> initPostion, Color color, int points)
    : position_(initPostion), color_(color),points_(points) {}

bool Material::MoveMaterial(std::pair<int, int> newPosition,
                            std::vector<Material*> enemy) {
	std::vector<std::pair<int, int>> available = CheckAvailableMoves(enemy);
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
