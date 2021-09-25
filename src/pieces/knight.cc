#include "knight.h"   // Knight

#include <iostream>    // std::ostream
#include <vector>     // std::vector

#include "color.h"    // Color
#include "piece.h"    // Piece
#include "position.h" // Position
#include "board.h"    // Board
#include "square.h"   // Square

Knight::Knight(Position initPostion, Color color)
    : Piece(initPostion, color, 3) {}


int Knight::value() const noexcept {
  return 3;
}

void Knight::Print(std::ostream& os) const noexcept {
  os << 'N';
}


//Returns an std::vector<Square> with all available positions a Knight piece
//can attack/move
std::vector<Square> Knight::AvailableMoves(Board& board) const
{
  std::cout << "Inside Knights AvailableMoves method\n";
  static const int kMovableDirections = 8;
  static const Position moves[kMovableDirections] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
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


bool Knight::MovePiece(Square newSquare,Board& board) {
  std::cout << "Inside KNIGHT method\n";
  if(currentMoves.empty())
  {
    std::cout << "KNIGHTKNIGHTKNIGHTKNIGHT currentMoves was empty\n";
    currentMoves = AvailableMoves(board);
    std::cout << "KNIGHTKNIGHTKNIGHTKNIGHT currentMoves size: "<< currentMoves.size() << "\n";
  }
  for(Square square : currentMoves){
    if(square == newSquare){
      //can move there
      std::cout << "Initiating KNIGHTKNIGHTKNIGHTKNIGHTKNIGHTKNIGHT movement\n";
      board.square(newSquare.GetPosition()).SetPiece(std::shared_ptr<Piece>(this));
      board.square(position_).SetPiece(nullptr);
      position_ = newSquare.GetPosition();
      currentMoves = AvailableMoves(board);

      return true;
    }
  }

  std::cout << "No move happened KNIGHTKNIGHTKNIGHTKNIGHTKNIGHTKNIGHThere\n";
  return false;
}
