#include "queen.h"    // Queen

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


Queen::Queen(Position initPostion, Color color)
    : Material(initPostion, color, 9) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<Position>
Queen::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<Position > available;
	Position tempPosition;
	// first = row / second = column
	int directions[2] = {-1, 1};
	for(int dir : directions) {
		tempPosition = position_;
		while(InBoard(tempPosition)) {
			tempPosition.x += dir;
			if(InBoard(tempPosition))
				available.push_back(tempPosition);
			else
				break;
		}
		tempPosition = position_;
		while(InBoard(tempPosition)) {
			tempPosition.y += dir;
			if(InBoard(tempPosition))
				available.push_back(tempPosition);
			else
				break;
		}
	}
	//diagonal
	for(int dirR : directions) {
		for(int dirC : directions) {
			tempPosition = position_;
			while(InBoard(tempPosition)) {
				tempPosition.x += dirR;
				tempPosition.y += dirC;
				if(InBoard(tempPosition))
					available.push_back(tempPosition);
				else
					break;
			}
		}
	}
	return available;
}
