#include "board.h"   // Board

#include <stdexcept> // std::out_of_range
#include <string>    // std::string
#include <ostream>   // std::ostream


template<int DimensionX, int DimensionY>
Board<DimensionX, DimensionY>::Board() {}

template<int DimensionX, int DimensionY>
void Board<DimensionX, DimensionY>::Init() noexcept {
  // Fill the board with initial positions of the pieces
}
template<int DimensionX, int DimensionY>
void Board<DimensionX, DimensionY>::Clear() noexcept {
  // Remove all pieces from the squares
}

template<int DimensionX, int DimensionY>
Square& Board<DimensionX, DimensionY>::square(const std::string& position) {
  if (position.length() != 2) {
    throw std::out_of_range("position length must be 2");
  }
  int y = 7 - (position[0] - '1');
  int x = position[1] - 'a';
  return square(x, y);
}

template<int DimensionX, int DimensionY>
Square& Board<DimensionX, DimensionY>::square(int x, int y) {
  if (x < 0 || x >= DimensionX || y < 0 || y >= DimensionY) {
    throw std::out_of_range("x or y coordinate out of range");
  }
  return square_[y][x];
}

template<int DimensionX, int DimensionY>
std::ostream& operator<<(std::ostream& os, const Board<DimensionX, DimensionY>& board) {
  //   a b c d e f g h
  // 8 R N B Q K B N R
  // 7 P P P P P P P P
  // 6 . . . . . . . .
  // 5 . . . . . . . .
  // 4 . . . . . . . .
  // 3 . . . . . . . .
  // 2 P P P P P P P P
  // 1 R N B Q K B N R
  return os;
}
