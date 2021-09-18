#include "knight.h"   // Knight

#include <utility>    // std::pair
#include <vector>     // std::vector

#include "color.h"    // Color
#include "material.h" // Material

Knight::Knight(std::pair<int, int> initPostion, Color color)
    : Material(initPostion, color, 3) {}

//TODO: Refactor
//TODO: Add piece collision
std::vector<std::pair<int, int>>
Knight::CheckAvailableMoves(const std::vector<Material*>& enemy) {
	std::vector<std::pair<int, int>> available;
	std::pair<int, int> tempPosition;

	int directions_double[2] = {-2, 2};
	int directions_single[2] = {-1, 1};
	for(int double_step : directions_double) {
		tempPosition = position_;
		tempPosition.first += double_step;
		std::pair<int, int> temp2_position = tempPosition;
		for(int single : directions_single) {
			tempPosition = temp2_position;
			tempPosition.second += single;
			if(InBoard(tempPosition))
				available.push_back(tempPosition);
			else
				break;
		}
	}
	for(int double_step : directions_double) {
		tempPosition = position_;
		tempPosition.second += double_step;
		std::pair<int, int> temp2_position = tempPosition;
		for(int single : directions_single) {
			tempPosition = temp2_position;
			tempPosition.first+=single;
			if(InBoard(tempPosition))
				available.push_back(tempPosition);
			else
				break;
		}
	}
	return available;
}
