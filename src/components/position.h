#ifndef CHESS_SRC_POSITION_H
#define CHESS_SRC_POSITION_H

#include <ostream> // std::ostream


class Position {
 public:
  int x, y;
  Position() = default;
  Position(int x, int y);
  bool InBoard() const noexcept;
  bool operator==(const Position& other) const noexcept;
  Position operator+(const Position& other) const noexcept;
  Position& operator+=(const Position& other) noexcept;
  friend std::ostream& operator<<(std::ostream&, const Position&);
};

#endif // CHESS_SRC_POSITION_H
