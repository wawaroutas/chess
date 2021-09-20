#include "location.h"

#include <ostream> // std::ostream


Location::Location(BoardFile file, int rank) : file_(file), rank_(rank) {}

bool Location::operator==(const Location& other) {
  return other.file_ == file_ && other.rank_ == rank_;
}

std::ostream& operator<<(std::ostream& os, const Location& location) {
  return os << location.file_ << location.rank_;
}
