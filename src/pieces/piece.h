#ifndef CHESS_SRC_PIECES_PIECE_H
#define CHESS_SRC_PIECES_PIECE_H

#include <ostream>    // std::ostream
#include <string>     // std::string
#include <vector>     // std::vector

#include "color.h"    // Color
#include "position.h" // Position
#include "board.h"    // Board


class Piece {
 public:
  Piece(Position initPostion, Color color, int points);
  //Returns true if Piece can move in Square target
  // True : Square not occupied || Square occupied && Square.Piece.Color != color_
  // False: Square occupied && Square.Piece.Color == color_
  bool canMove(Square& target) const;
  bool MovePiece(Position newPosition, Board<8,8> board);
  virtual std::vector<Position>
  AvailableMoves(Board<8,8> board) const = 0;
  // virtual std::vector<Position>
  // AvailableMoves(const Board<8,8>& board) const = 0;
  std::vector<Position>
  AvailableCaptures(Board<8,8>) const;
  //-----------Getters&Setters--------
  Color GetColor() const noexcept;
  Position GetPosition() const noexcept;
  virtual int value() const noexcept = 0;
  friend std::ostream& operator<<(std::ostream&, const Piece&);
 protected:
  virtual void Print(std::ostream&) const noexcept = 0;
  Position position_;
  const Color color_;
  int points_;
};

#endif // CHESS_SRC_PIECES_Piece_H
