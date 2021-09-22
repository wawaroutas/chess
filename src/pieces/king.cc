#include "king.h"     // King

#include <ostream>    // std::ostream
#include <vector>     // std::vector
#include <limits>     // numeric_limits
#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square

King::King(Position initPostion, Color color)
    : Piece(initPostion, color, 1000) {}


//Returns an std::vector<Square> with all available positions a King piece
//can attack/move
//TODO add check
std::vector<Square> King::AvailableMoves(Board& board) const {
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {1, 0}, {0, 1}, {1, 1}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Square> available;
  for (Position move : moves) {
    if((position_ + move).InBoard())
    {
      Square square = board.square(position_+move);
      if(canMove(square))
        available.push_back(square);
    }
  }
  return available;
}

int King::value() const noexcept {
  return std::numeric_limits<int>::max();
}

void King::Print(std::ostream& os) const noexcept {
  os << 'K';
}


bool King::MovePiece(Square newSquare,Board board){
  std::cout << "Inside KING method\n";
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
