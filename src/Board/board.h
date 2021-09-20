#ifndef CHESS_SRC_BOARD_BOARD_H
#define CHESS_SRC_BOARD_BOARD_H

#include <ostream>  // std::ostream
#include <string>   // std::string

#include "square.h" // Square

template<int DimensionX, int DimensionY>
class Board {
 public:
  Board();
  void Init() noexcept;
  void Clear() noexcept;
  Square& square(const std::string&);
  Square& square(int, int);
  friend std::ostream& operator<<(std::ostream&, const Board&);
 private:
  Square square_[DimensionY][DimensionX];
};

#endif // CHESS_SRC_BOARD_BOARD_H