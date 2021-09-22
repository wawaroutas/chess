#ifndef CHESS_SRC_PLAYER_H
#define CHESS_SRC_PLAYER_H

#include "piece.h"
#include "board.h"
#include <string>
#include <vector>
class Player{
public:
  Player();
  Player(std::string name,std::vector<Piece*> pieces);
  void RemovePiece(Piece* piece);
  void AddPoints(int points);
  void Init(Board board,Color c);
  void MakeMove(Board board);
  //-----Getters and Setters---------//
  std::vector<Piece*> GetPieces() const noexcept;
  int GetPoints() const noexcept;
  std::string GetName() const noexcept;
  void SetName(std::string newName);
  void SetPieces(std::vector<Piece*> pieces);
  bool operator==(const Player& other);
private:
  std::string name_;
  std::vector<Piece*> pieces_;
  int points_;
};

#endif  //CHESS_SRC_PLAYER_H
