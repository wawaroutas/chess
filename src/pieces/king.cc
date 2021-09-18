#include "king.h"     // King

#include "position.h"    // Position
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material

King::King(Position initPostion, Color color)
    : Material(initPostion, color, 1000) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<Position>
King::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<Position > available;
	Position tempPosition;
	return available;
}
