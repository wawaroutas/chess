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
    std::cout <<" game running\n";
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
  std::cout << "Board initialized\n";
  players_.push_back(Player());
  players_.push_back(Player());
  players_[0].Init(board_,Color::kBlack);
  players_[1].Init(board_,Color::kWhite);
  currentTurn_ = players_[1];

  std::cout << "Chess initialized\n";
}
