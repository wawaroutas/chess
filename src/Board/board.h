#ifndef CHESS_SRC_BOARD_BOARD_H
#define CHESS_SRC_BOARD_BOARD_H

#include <ostream>    // std::ostream
#include <string>     // std::string

#include "square.h"   // Square
#include "position.h" // Position


class Board {
 public:
  // Sets the boards squares colors and positions
  //   a b c d e f g h
  // 8 ▓ ░ ▓ ░ ▓ ░ ▓ ░
  // 7 ░ ▓ ░ ▓ ░ ▓ ░ ▓
  // 6 ▓ ░ ▓ ░ ▓ ░ ▓ ░
  // 5 ░ ▓ ░ ▓ ░ ▓ ░ ▓
  // 4 ▓ ░ ▓ ░ ▓ ░ ▓ ░
  // 3 ░ ▓ ░ ▓ ░ ▓ ░ ▓
  // 2 ▓ ░ ▓ ░ ▓ ░ ▓ ░
  // 1 ░ ▓ ░ ▓ ░ ▓ ░ ▓
  Board();
  // Sets the pieces on the board to their initial positions
  void Init() noexcept;
  // Removes all the pieces from the board
  void Clear() noexcept;
  Square& square(const std::string&);
  Square& square(int, int);
  Square& square(const Position&);
  friend std::ostream& operator<<(std::ostream&, const Board&);
 private:
  static const int kRanks = 8;
  static const int kFiles = 8;
  Square square_[kRanks][kFiles];
};

#endif // CHESS_SRC_BOARD_BOARD_H
