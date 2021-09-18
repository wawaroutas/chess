#include "queen.h"    // Queen

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


Queen::Queen(std::pair<int, int> initPostion, Color color) 
    : Material(initPostion, color, 9) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<std::pair<int, int>> 
Queen::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<std::pair<int,int> > available;
	std::pair<int, int> tempPosition;
	// first = row / second = column
	int directions[2] = {-1, 1};
	for(int dir : directions) {
		tempPosition = position_;
		while(InBoard(tempPosition)) {
			tempPosition.first+=dir;
			if(InBoard(tempPosition))
				available.push_back(tempPosition);
			else
				break;
		}
		tempPosition = position_;
		while(InBoard(tempPosition)) {
			tempPosition.second+=dir;
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
				tempPosition.first+=dirR;
				tempPosition.second+=dirC;
				if(InBoard(tempPosition))
					available.push_back(tempPosition);
				else
					break;
			}
		}
	}
	return available;
}
