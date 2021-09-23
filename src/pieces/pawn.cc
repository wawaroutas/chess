#include "pawn.h"     // Pawn

#include <iostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square

Pawn::Pawn(Position initPostion,Color color)
    : Piece(initPostion, color, 1),firstMove_(true) {}

//Returns an std::vector<Square> with all available positions a Pawn piece
//can capture/move
//TODO: Add en pessant
std::vector<Square> Pawn::AvailableMoves(Board& board) const {
	std::vector<Square> available;
  Position move = {};
  if(firstMove_){
     move = {0,2};
     // firstMove_ = false;
  }
  else{
     move = {0,1};
  }
  Position captures[] = {{1,1},{-1,1}};
  if((position_ + move).InBoard())
  {
    Square square = board.square(position_+move);
    if(canMove(square))
      available.push_back(square);
  }

  for(Position capture : captures)
  {
    if((position_+capture).InBoard()){
      Square square = board.square(position_+capture);
      if(square.Occupied())
        if(square.GetPiece()->GetColor() != color_)
          available.push_back(square);
    }
  }
  return available;
}

bool Pawn::MovePiece(Square newSquare,Board& board) {
  std::cout << "Inside of Pawn method\n";
  if(currentMoves.empty())
  {
    std::cout << "PAWNPAWNPAWNPAWN currentMoves was empty\n";
    currentMoves = AvailableMoves(board);
    std::cout << "PAWNPAWNPAWNPAWN currentMoves size: "<< currentMoves.size() << "\n";
  }
  for(Square square : currentMoves){
    if(square == newSquare){
      //can move there
      std::cout << "Initiating PAWNPAWNPAWNPAWNPAWNPAWNmovement\n";
      board.square(newSquare.GetPosition()).SetPiece(std::shared_ptr<Piece>(this));
      board.square(position_).SetPiece(nullptr);
      position_ = newSquare.GetPosition();
      currentMoves = AvailableMoves(board);
      firstMove_ = false;
      return true;
    }
  }
  firstMove_ = true;
  std::cout << "No move happened PAWNPAWNPAWNPAWNPAWNPAWNPAWNPAWNhere\n";
  return false;
}


int Pawn::value() const noexcept {
  return 1;
}

void Pawn::Print(std::ostream& os) const noexcept {
  os << 'P';
}
