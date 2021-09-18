#include "king.h"     // King

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material

King::King(std::pair<int, int> initPostion, Color color)
    : Material(initPostion, color, 1000) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<std::pair<int, int>>
King::CheckAvailableMoves(const std::vector<Material*> enemy) {
	std::vector<std::pair<int, int> > available;
	std::pair<int, int> tempPosition;
	return available;
}
