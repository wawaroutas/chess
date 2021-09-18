#ifndef CHESS_SRC_POSITION_H
#define CHESS_SRC_POSITION_H

struct Position {
 public:
  int x, y;
  Position() = default;
  Position(int x,int y): x(x) , y(y){}
  bool operator==(const Position& other)
  {
    return this-> x == other.x && this->y == other.y;
  }
};

#endif /* CHESS_SRC_POSITION_H  */
