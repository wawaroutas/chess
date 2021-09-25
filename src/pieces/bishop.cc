#include "bishop.h"   // Bishop

#include <ostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square


Bishop::Bishop(Position initPostion, Color color)
    : Piece(initPostion, color, 3) {}

//Returns an std::vector<Square> with all available positions a Bishop piece
//can attack/move
std::vector<Square> Bishop::AvailableMoves(Board& board) const {
  static const int kMovableDirections = 4;
  static const Position moves[kMovableDirections] = {
    {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
  };
	std::vector<Square> available;
  for (Position move : moves) {
    Position newPosition = position_ + move;
    while((newPosition).InBoard()){
      Square square = board.square(newPosition);
      if(canMove(square))
        available.push_back(square);
      if(!square.Occupied())
        newPosition+=move;
      else
        break; //Square occupied so move to another direction
    }
  }
  return available;
}

int Bishop::value() const noexcept {
  return 3;
}

void Bishop::Print(std::ostream& os) const noexcept {
  os << 'B';
}



bool Bishop::MovePiece(Square newSquare,Board& board){
  std::cout << "Inside BISHOP method\n";
  if(currentMoves.empty())
  {
    std::cout << "currentMoves was empty\n";
    currentMoves = AvailableMoves(board);
    std::cout << "currentMoves size: "<< currentMoves.size() << "\n";
    for(Square sq : currentMoves)
      std::cout << sq << '\n';
  }
  for(Square square : currentMoves){
    if(square == newSquare){
      //can move there
      std::cout << "Initiating movement\n";
      board.square(newSquare.GetPosition()).SetPiece(std::shared_ptr<Piece>(this));
      board.square(position_).SetPiece(nullptr);
      position_ = newSquare.GetPosition();
      currentMoves.clear();
      currentMoves = AvailableMoves(board);
      return true;
    }
  }
  std::cout << "No move happened here\n";
  return false;
}
