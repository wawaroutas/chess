#include "board.h"    // Board

#include <memory>     // std::make_shared()
#include <ostream>    // std::ostream
#include <stdexcept>  // std::out_of_range()
#include <string>     // std::string

#include "color.h"    // Color
#include "position.h" // Position
#include "chesspieces.h" 


Board::Board() {
  for (int i = 0; i < kRanks; ++i) {
    for (int j = 0; j < kFiles; ++j) {
      square_[i][j].SetPosition(j, i);
      if ((i + j) % 2) {
        square_[i][j].SetColor(Color::kWhite);
      } else {
        square_[i][j].SetColor(Color::kBlack);
      }
    }
  }
}

void Board::Init() noexcept {
  square_[0][0].SetPiece(std::make_shared<Rook>(Position(0, 0), Color::kBlack));
  square_[0][2].SetPiece(std::make_shared<Bishop>(Position(0, 2), Color::kBlack));
  square_[0][1].SetPiece(std::make_shared<Knight>(Position(0, 1), Color::kBlack));
  square_[0][3].SetPiece(std::make_shared<Queen>(Position(0, 3), Color::kBlack));
  square_[0][4].SetPiece(std::make_shared<King>(Position(0, 4), Color::kBlack));
  square_[0][5].SetPiece(std::make_shared<Bishop>(Position(0, 5), Color::kBlack));
  square_[0][6].SetPiece(std::make_shared<Knight>(Position(0, 6), Color::kBlack));
  square_[0][7].SetPiece(std::make_shared<Rook>(Position(0, 7), Color::kBlack));
  square_[1][0].SetPiece(std::make_shared<Pawn>(Position(1, 0), Color::kBlack));
  square_[1][1].SetPiece(std::make_shared<Pawn>(Position(1, 1), Color::kBlack));
  square_[1][2].SetPiece(std::make_shared<Pawn>(Position(1, 2), Color::kBlack));
  square_[1][3].SetPiece(std::make_shared<Pawn>(Position(1, 3), Color::kBlack));
  square_[1][4].SetPiece(std::make_shared<Pawn>(Position(1, 4), Color::kBlack));
  square_[1][5].SetPiece(std::make_shared<Pawn>(Position(1, 5), Color::kBlack));
  square_[1][6].SetPiece(std::make_shared<Pawn>(Position(1, 6), Color::kBlack));
  square_[1][7].SetPiece(std::make_shared<Pawn>(Position(1, 7), Color::kBlack));

  square_[7][0].SetPiece(std::make_shared<Rook>(Position(7, 0), Color::kWhite));
  square_[7][1].SetPiece(std::make_shared<Knight>(Position(7, 1), Color::kWhite));
  square_[7][2].SetPiece(std::make_shared<Bishop>(Position(7, 2), Color::kWhite));
  square_[7][3].SetPiece(std::make_shared<Queen>(Position(7, 3), Color::kWhite));
  square_[7][4].SetPiece(std::make_shared<King>(Position(7, 4), Color::kWhite));
  square_[7][5].SetPiece(std::make_shared<Bishop>(Position(7, 5), Color::kWhite));
  square_[7][6].SetPiece(std::make_shared<Knight>(Position(7, 6), Color::kWhite));
  square_[7][7].SetPiece(std::make_shared<Rook>(Position(7, 7), Color::kWhite));
  square_[6][0].SetPiece(std::make_shared<Pawn>(Position(6, 0), Color::kWhite));
  square_[6][1].SetPiece(std::make_shared<Pawn>(Position(6, 1), Color::kWhite));
  square_[6][2].SetPiece(std::make_shared<Pawn>(Position(6, 2), Color::kWhite));
  square_[6][3].SetPiece(std::make_shared<Pawn>(Position(6, 3), Color::kWhite));
  square_[6][4].SetPiece(std::make_shared<Pawn>(Position(6, 4), Color::kWhite));
  square_[6][5].SetPiece(std::make_shared<Pawn>(Position(6, 5), Color::kWhite));
  square_[6][6].SetPiece(std::make_shared<Pawn>(Position(6, 6), Color::kWhite));
  square_[6][7].SetPiece(std::make_shared<Pawn>(Position(6, 7), Color::kWhite));
}

void Board::Clear() noexcept {
  for (int i = 0; i < kRanks; ++i) {
    for (int j = 0; j < kFiles; ++j) {
      square_[i][j].SetPiece(nullptr);
    }
  }
}

Square& Board::square(const std::string& position) {
  if (position.length() != 2) {
    throw std::out_of_range("position length must be 2");
  }
  int y = 7 - (position[0] - '1');
  int x = position[1] - 'a';
  return square(x, y);
}

Square& Board::square(const Position& position) {
  return square(position.x, position.y);
}

Square& Board::square(int x, int y) {
  if (x < 0 || x >= kFiles || y < 0 || y >= kRanks) {
    throw std::out_of_range("x or y coordinate out of range");
  }
  return square_[y][x];
}


std::ostream& operator<<(std::ostream& os, const Board& board) {
  //   a b c d e f g h
  // 8 R N B Q K B N R
  // 7 P P P P P P P P
  // 6 . . . . . . . .
  // 5 . . . . . . . .
  // 4 . . . . . . . .
  // 3 . . . . . . . .
  // 2 P P P P P P P P
  // 1 R N B Q K B N R
  os << "  ";
  for (int i = 0; i < board.kFiles; ++i) {
    os << static_cast<char>(i + 'a') << ' ';
  }
  os << '\n';
  for (int i = 0; i < board.kRanks; ++i) {
    os << board.kRanks - i << ' ';
    for (int j = 0; j < board.kFiles; ++j) {
      os << board.square_[i][j] << ' ';
    }
    os << '\n';
  }
  return os;
}
