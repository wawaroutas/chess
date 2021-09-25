#include <cstdlib>       // EXIT_SUCCESS
#include <iostream>      // std::cout
#include <vector>        // std::vector

#include "chesspieces.h" // King, Queen, Rook, Knight, Bishop, Pawn
#include "color.h"       // Color
#include "position.h"    // Position
#include "square.h"      // Square
#include "board.h"       // Board
#include "player.h"
#include "chess.h"

int main() {
  //Chess chess;
  Board  board;
  board.Init();
  std::string input,pos1,pos2;
  std::cout << board;
  Square from = board.square("b1");
  Square to = board.square("c3");
  from.GetPiece()->MovePiece(to,board);
  std::cout << board;
  // while(true)
  // {
  //   std::cin >> input;
  //   int pos = input.find("->");
  //   pos1 = input.substr(0,pos);
  //   pos2 = input.substr(pos+2,std::string::npos);
  //   Square from = board.square(pos1);
  //   Square to = board.square(pos2);
  //   std::cout << "Before move \n";
  //   if(from.GetPiece()==nullptr)
  //     std::cout << "Square from piece now null\n";
  //   if(to.GetPiece()==nullptr)
  //     std::cout << "Square to piece now null\n";
  //
  //   from.GetPiece()->MovePiece(to,board);
  //
  //   std::cout << "after move \n";
  //   if(from.GetPiece()==nullptr)
  //     std::cout << "Square from piece now null\n";
  //   if(to.GetPiece()==nullptr)
  //     std::cout << "Square to piece now null\n";
  //   std::cout << board;
  // }

  // Position a(0,0), b(7,7);
	// Board<8,8> e;
	// e.square(a);
	// std::cout << "a(0,0):" << a << ' ' << b;
	// Bishop kn({4,7}, Color::kWhite);
	// Bishop kn1({3,6}, Color::kWhite);
	// Bishop kn2({5,6}, Color::kBlack);
	// std::vector<Piece*> v;
	//  v.push_back(&kn2);
	//  v.push_back(&kn1);
	// auto yo = kn.AvailableMoves(v);
	// for (auto& [x, y] : yo) {
	// 	std::cout << '(' << x << ',' << y << ")\n";
	// }
	return EXIT_SUCCESS;
}
