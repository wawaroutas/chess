#ifndef CHESS_SRC_POSITION_H
#define CHESS_SRC_POSITION_H

struct Position {
 public:
  Position() = default;
  int x, y;
  Position() = default;
  Position(int x,int y): x(x) , y(y){}
  bool operator==(const Position& other) const noexcept {
    return x == other.x && y == other.y;
  }
};

#endif /* CHESS_SRC_POSITION_H  */
