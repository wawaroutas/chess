#include "Location.h"

#include <string> // std::string, std::to_string()
#include <map>    // std::map



bool Location::operator==(const Location& other)
{
  return other.file_ == file_ && other.rank_ == rank_;
}


std::ostream& operator<<(std::ostream& os,const Location& location)
{
  static std::map<BoardFile,std::string> strings= {{BoardFile::A,"A"},
  {BoardFile::B,"B"},{BoardFile::C,"C"},{BoardFile::D,"D"},{BoardFile::E,"E"},
  {BoardFile::F,"F"},{BoardFile::G,"G"},{BoardFile::H,"H"},};
  return os << std::string(strings[location.file_] + std::to_string(location.rank_));
}
