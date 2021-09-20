#ifndef CHESS_SRC_BOARD_BOARDFILE_H
#define CHESS_SRC_BOARD_BOARDFILE_H

#include <iostream> // std::ostream

enum BoardFile : char {
  A = 'A',
  B,
  C,
  D,
  E,
  F,
  G,
  H
};

inline std::ostream& operator<<(std::ostream& os, const BoardFile file) {
  return os << static_cast<char>(file);
}

#endif /* CHESS_SRC_BOARD_FILE_H  */
