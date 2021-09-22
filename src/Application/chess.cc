#include "chess.h"
#include "player.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Chess::Chess()
{
  Init();
  Run();
}


void Chess::Run()
{
  bool gamerunning=true;
  while(gamerunning)
  {
        currentTurn_.MakeMove(board_);
        SwitchTurn();
  }
}

void Chess::SwitchTurn()
{
  if(currentTurn_ == players_[0])
    currentTurn_ = players_[1];
  currentTurn_ = players_[0];
}
void Chess::Init()
{
  board_.Init();
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  if(std::rand()%2)
  {
    players_[0].Init(board_,Color::kBlack);
    players_[1].Init(board_,Color::kWhite);
    currentTurn_ = players_[1];
  }
  else
  {
    players_[1].Init(board_,Color::kBlack);
    players_[0].Init(board_,Color::kWhite);
    currentTurn_ = players_[0];
  }
}
