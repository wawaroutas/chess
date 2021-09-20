#ifndef CHESS_SRC_BOARD_LOCATION_H
#define CHESS_SRC_BOARD_LOCATION_H

#include "boardfile.h" // BoardFile
#include <string> //std::string

class Location
{
public:
  const BoardFile file_;
  const int rank_;
  Location(BoardFile file,int rank);
  std::string toString();
  bool operator==(const Location& other);
};


#endif /* CHESS_SRC_BOARD_FILE_H  */
