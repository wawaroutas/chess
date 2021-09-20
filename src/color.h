#ifndef CHESS_SRC_COLOR_H
#define CHESS_SRC_COLOR_H

#include <map>
#include <iostream>

enum class Color {
  kBlack,
  kWhite
};

inline std::ostream& operator>>(std::ostream& os,const Color& color)
{
  std::map<Color,std::string> values = { {Color::kBlack,"BLACK"},{Color::kWhite,"WHITE"}};
  return os << values[color];
}

#endif // CHESS_SRC_COLOR_H
