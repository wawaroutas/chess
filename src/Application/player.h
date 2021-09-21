#ifndef CHESS_SRC_PLAYER_H
#define CHESS_SRC_PLAYER_H

#include <vector>  // std::vector

#include "piece.h" // Piece
#include "board.h" // Board

class Player{
public:
  Player();
  Player(const char* name,std::vector<Piece*> pieces);
  void RemovePiece(Piece* piece);
  void AddPoints(int points);
  //-----Getters and Setters---------//
  std::vector<Piece*> GetPieces() const noexcept;
  int GetPoints() const noexcept;
  const char* GetName() const noexcept;
  void SetName(const char* newName);
  void SetPieces(std::vector<Piece*> pieces);
  void Init(Board board);
private:
  const char* name_;
  std::vector<Piece*> pieces_;
  int points_;
};

#endif  //CHESS_SRC_PLAYER_H
