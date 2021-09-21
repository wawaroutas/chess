#ifndef CHESS_SRC_PLAYER_H
#define CHESS_SRC_PLAYER_H

#include "piece.h"

class Player{
public:
  Player(const char* name,std::vector<Piece*> pieces);
  std::vector<Piece*> GetPieces() const noexcept;
  int GetPoints() const noexcept;
  void AddPoints(int points);
  const char* GetName() const noexcept;
  void RemovePiece(Piece* piece);
private:
  const char* name_;
  std::vector<Piece*> pieces_;
  int points_;
};

#endif  //CHESS_SRC_PLAYER_H
