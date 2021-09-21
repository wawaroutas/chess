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
  bool MovePiece(Position newPosition, const std::vector<Piece*>& enemy);
  virtual std::vector<Position>
  AvailableMoves(const std::vector<Piece*>& enemy) const = 0;
  virtual std::vector<Position>
  AvailableAttacks(const std::vector<Piece*>& enemy) const = 0;
  
  //-----------Getters&Setters--------
  Color GetColor() const noexcept;
  Position GetPosition() const noexcept;
  //Change later
  virtual int value() const noexcept = 0;
  friend std::ostream& operator<<(std::ostream&, const Piece&);
 protected:
  virtual void Print(std::ostream&) const noexcept = 0;
  Position position_;
  const Color color_;
  int points_;
};
//Helpful for finding if a position is occupied by another piece in the board
//Returns true if it is occupied,false if it is free
bool PositionValid(Position pos, const std::vector<Piece*>& enemy, Color);

#endif // CHESS_SRC_PIECES_Piece_H
