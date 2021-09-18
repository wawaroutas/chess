#include "pawn.h"        // Pawn

#include <vector>        // std::vector

#include "color.h"       // Color
#include "material.h"    // Material
#include "position.h"    // Position


Pawn::Pawn(Position initPostion, Color color) 
    : Material(initPostion, color, 1) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<Position> 
Pawn::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<Position> available;
	Position tempPosition;
	return available;
}
