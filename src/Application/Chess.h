#ifndef CHESS_SRC_APPLICATION_CHESS_H
#define CHESS_SRC_APPLICATION_CHESS_H

#include "board.h"
#include "player.h"
#include "chesspieces.h"


class Chess{
public:
  Chess();
private:
  void run();
  Board board;
  std::vector<Player> players;
  Player currentTurn;

};

#endif //  CHESS_SRC_APPLICATION_CHESS_H
