#ifndef CHESS_SRC_POSITION_H
#define CHESS_SRC_POSITION_H

class Position {
 public:
  int x, y;
  Position() = default;
  Position(int x, int y);
  bool InBoard() const noexcept;
  bool operator==(const Position& other) const noexcept;
  Position operator+(const Position& other) const noexcept;
  Position& operator+=(const Position& other );
};

#endif // CHESS_SRC_POSITION_H
