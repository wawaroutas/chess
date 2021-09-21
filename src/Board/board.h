#ifndef CHESS_SRC_BOARD_BOARD_H
#define CHESS_SRC_BOARD_BOARD_H

#include <ostream>    // std::ostream
#include <string>     // std::string

#include "square.h"   // Square
#include "position.h" // Position


class Board {
 public:
  Board();
  void Init() noexcept;
  void Clear() noexcept;
  Square& square(const std::string&);
  Square& square(int, int);
  Square& square(const Position&);
  void Print(std::ostream&) const;
  // friend std::ostream& operator<<<>(std::ostream&, const Board&);
 private:
  static const int Ranks = 8;
  static const int Files = 8;
  Square square_[Ranks][Files];
};

#endif // CHESS_SRC_BOARD_BOARD_H
