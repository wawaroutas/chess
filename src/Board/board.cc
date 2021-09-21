#include "board.h"    // Board

#include <ostream>    // std::ostream
#include <stdexcept>  // std::out_of_range
#include <string>     // std::string

#include "position.h" // Position


Board::Board() {
  if (Files < 0 || Ranks < 0) {
    throw std::out_of_range("Files and Ranks must be positive integers");
  }
  // Setting the color of the Boards Squares
  for (int i = 0; i < Ranks; ++i) {
    for (int j = 0; j < Files; ++j) {
      if (((i + j) % 2) == 0) {
        square_[i][j].SetColor(Color::kWhite);
      } else {
        square_[i][j].SetColor(Color::kBlack);
      }
    }
  }
}

void Board::Init() noexcept {
  // Fill the board with initial positions of the pieces
}
void Board::Clear() noexcept {
  // Remove all pieces from the squares
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
  if (x < 0 || x >= Files || y < 0 || y >= Ranks) {
    throw std::out_of_range("x or y coordinate out of range");
  }
  return square_[y][x];
}

//
// std::ostream& operator<<(std::ostream& os, const Board& board) {
//   //   a b c d e f g h
//   // 8 R N B Q K B N R
//   // 7 P P P P P P P P
//   // 6 . . . . . . . .
//   // 5 . . . . . . . .
//   // 4 . . . . . . . .
//   // 3 . . . . . . . .
//   // 2 P P P P P P P P
//   // 1 R N B Q K B N R
//   os << "  ";
//   for (int i = 0; i < Files; ++i) {
//     os << static_cast<char>(i + 'a') << ' ';
//   }
//   os << '\n';
//   for (int i = 0; i < Ranks; ++i) {
//     os << Ranks - i << ' ';
//     for (int j = 0; j < Files; ++j) {
//       os << board.square_[i][j] << ' ';
//     }
//     os << '\n';
//   }
//   return os;
// }

void Board::Print(std::ostream& os) const {
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
  for (int i = 0; i < Files; ++i) {
    os << static_cast<char>(i + 'a') << ' ';
  }
  os << '\n';
  for (int i = 0; i < Ranks; ++i) {
    os << Ranks - i << ' ';
    for (int j = 0; j < Files; ++j) {
      os << square_[i][j] << ' ';
    }
    os << '\n';
  }
}
