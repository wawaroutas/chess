#ifndef CHESS_SRC_POSITION_H
#define CHESS_SRC_POSITION_H

struct Position {
 public:
  Position() = default;
  int x, y;
  bool operator==(const Position& other) const {
    return x == other.x && y == other.y;
  }
};

#endif /* CHESS_SRC_POSITION_H  */
