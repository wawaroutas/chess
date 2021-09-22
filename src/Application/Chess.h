#ifndef CHESS_SRC_APPLICATION_CHESS_H
#define CHESS_SRC_APPLICATION_CHESS_H

#include "board.h"
#include "player.h"
#include "chesspieces.h"


class Chess{
public:
  Chess();
  void Init();
  void Run();
private:
  void SwitchTurn();
  void run();
  Board board_;
  std::vector<Player> players_;
  Player currentTurn_;

};

#endif //  CHESS_SRC_APPLICATION_CHESS_H
