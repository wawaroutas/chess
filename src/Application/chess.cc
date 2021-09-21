#include "chess.h"
#include "player.h"



Chess::Chess()
{
  Init();
}


void Chess::Init()
{
  board_.Init();
  for(Player player : players_)
    player.Init(board_);
}
