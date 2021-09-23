#include "queen.h"    // Queen

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square


Queen::Queen(Position initPostion, Color color)
    : Piece(initPostion, color, 9) {}

//Returns an std::vector<Square> with all available positions a Queen piece
//can capture/move
std::vector<Square> Queen::AvailableMoves(Board& board) const {
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Square> available;
  for (Position move : moves) {
    while((position_+move).InBoard()){
      Square square = board.square(position_+move);
      if(canMove(square))
        available.push_back(square);
      if(!square.Occupied())
        move+=move;
      else
        break; //Square occupied so move to another direction
    }
  }
  return available;
}

int Queen::value() const noexcept {
  return 9;
}

void Queen::Print(std::ostream& os) const noexcept {
  os << 'Q';
}


bool Queen::MovePiece(Square newSquare,Board& board){
  std::cout << "Inside QUEEN method\n";
  if(currentMoves.empty())
  {
    std::cout << "currentMoves was empty\n";
    currentMoves = AvailableMoves(board);
    std::cout << "currentMoves size: "<< currentMoves.size() << "\n";
  }
  for(Square square : currentMoves){
    if(square == newSquare){
      //can move there
      std::cout << "Initiating movement\n";
      board.square(newSquare.GetPosition()).SetPiece(std::shared_ptr<Piece>(this));
      board.square(position_).SetPiece(nullptr);
      position_ = newSquare.GetPosition();
      currentMoves = AvailableMoves(board);
      return true;
    }
  }
  std::cout << "No move happened here\n";
  return false;
}
