#include "pawn.h"     // Pawn

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


Pawn::Pawn(std::pair<int,int> initPostion,Color color) 
    : Material(initPostion, color, 1) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<std::pair<int, int>> 
Pawn::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<std::pair<int, int> > available;
	std::pair<int, int> tempPosition;
	return available;
}
