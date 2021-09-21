#ifndef CHESS_SRC_BOARD_SQUARE_H
#define CHESS_SRC_BOARD_SQUARE_H

#include <memory>     // std::shared_ptr
#include <ostream>    // std::ostream

#include "color.h"    // Color
#include "position.h" // Position

class Piece;

class Square {
 public:
  Square();
  Square(Position position, Color color, std::shared_ptr<Piece> piece);
  Position GetPosition() const;
  Color GetColor() const;
  Piece* GetPiece() const;
  void SetPosition(int x, int y);
  void SetPiece(std::shared_ptr<Piece> piece);
  void SetColor(const Color);
  bool Occupied() const;
  bool operator==(const Square& other);
  friend std::ostream& operator<<(std::ostream&, const Square&);
 private:
  Position position_;
  Color color_;
  std::shared_ptr<Piece> piece_;
};

#endif // CHESS_SRC_BOARD_SQUARE_H
