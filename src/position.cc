#include "position.h"


Position::Position(int x,int y): x(x), y(y) {}

//Returns true if 2 position instances are equal, false otherwise
bool Position::operator==(const Position& other) const noexcept {
  return x == other.x && y == other.y;
}
