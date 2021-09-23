#ifndef CHESS_SRC_PIECES_PIECE_H
#define CHESS_SRC_PIECES_PIECE_H

#include <iostream>    // std::ostream
#include <string>     // std::string
#include <vector>     // std::vector

#include "color.h"    // Color
#include "position.h" // Position
#include "board.h"    // Board


class Piece {
 public:
  Piece(Position initPostion, Color color, int points);
  virtual bool MovePiece(Square newPosition,Board& board) = 0;
  //-----------Getters&Setters--------
  Color GetColor() const noexcept;
  Position GetPosition() const noexcept;
  virtual int value() const noexcept = 0;
  std::vector<Square> GetCurrentMoves() const noexcept;
  friend std::ostream& operator<<(std::ostream&, const Piece&);
 protected:
  std::vector<Square> currentMoves;
  virtual void Print(std::ostream&) const noexcept = 0;
  Position position_;
  const Color color_;
  int points_;
  //Returns true if Piece can move in Square target
  // True : Square not occupied || Square occupied && Square.Piece.Color != color_
  // False: Square occupied && Square.Piece.Color == color_
  bool canMove(Square& target) const;
  //Returns an std::vector<Square> with all available positions a piece
  //can capture/move
  virtual std::vector<Square> AvailableMoves(Board& board) const = 0;
  //Returns an std::vector<Square> with only positions a Piece can capture
  std::vector<Square> AvailableCaptures(Board&) const;
};

#endif // CHESS_SRC_PIECES_Piece_H
