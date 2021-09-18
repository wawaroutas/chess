#include "bishop.h"   // Bishop

#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material
#include "position.h" // Position


Bishop::Bishop(Position initPostion, Color color)
    : Material(initPostion, color, 3) {}


//TODO: Add piece collision
std::vector<Position>
Bishop::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<Position> available;
	Position tempPosition;
	// first = row / second = column
	int directions[2] = {-1, 1};
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
