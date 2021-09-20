#include "position.h" // Position

#include <ostream>    // std::ostream


Position::Position(int xx, int yy): x(xx), y(yy) {}

bool Position::InBoard() const noexcept {
  return x <= 8 && x > 0 && y <= 8 && y > 0;
}

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

Position& Position::operator+=(const Position& other) noexcept {
  x = x + other.x;
  y = y + other.y;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Position& position) {
  os << position.y + 7 + 'a' << position.x + '1';
  return os;
}