#include "bishop.h"   // Bishop

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material


Bishop::Bishop(std::pair<int, int> initPostion, Color color)
    : Material(initPostion, color, 3) {}


//TODO: Add piece collision
std::vector<std::pair<int, int>>
Bishop::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<std::pair<int, int>> available;
	std::pair<int, int> tempPosition;
	// first = row / second = column
	int directions[2] = {-1, 1};
	for(int dirR : directions) {
		for(int dirC : directions) {
			tempPosition = position_;
			while(InBoard(tempPosition)) {
				tempPosition.first += dirR;
				tempPosition.second += dirC;
				if(InBoard(tempPosition))
					available.push_back(tempPosition);
				else
					break;
			}
		}
	}
	return available;
}
