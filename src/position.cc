#include "position.h"


Position::Position(int x, int y): x(x), y(y) {}

// Returns true if the two positions x and y coordinates are equal
bool Position::operator==(const Position& other) const noexcept {
  return x == other.x && y == other.y;
}

Position Position::operator+(const Position& other) const noexcept {
  Position p(x, y);
  p.x += other.x;
  p.y += other.y;
  return p;
}
