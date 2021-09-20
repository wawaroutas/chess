#ifndef CHESS_SRC_BOARD_BOARDFILE_H
#define CHESS_SRC_BOARD_BOARDFILE_H
#include <map>
#include <iostream>
enum BoardFile {
  A = 1,
  B,
  C,
  D,
  E,
  F,
  G,
  H
};
inline std::ostream& operator<<(std::ostream& os,const BoardFile file)
{
  static std::map<BoardFile,std::string> strings= {{BoardFile::A,"A"},
  {BoardFile::B,"B"},{BoardFile::C,"C"},{BoardFile::D,"D"},{BoardFile::E,"E"},
  {BoardFile::F,"F"},{BoardFile::G,"G"},{BoardFile::H,"H"},};
  return os << strings[file];
}
#endif /* CHESS_SRC_BOARD_FILE_H  */
