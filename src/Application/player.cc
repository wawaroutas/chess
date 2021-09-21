#include "player.h"




Player::Player(const char* name,std::vector<Piece*> pieces):name_(name),pieces_(pieces),
points_(0){}

//---------Getters--------/
std::vector<Piece*> Player::GetPieces() const noexcept{return pieces_;}
int Player::GetPoints() const noexcept {return points_;}
const char* Player::GetName() const noexcept {return name_;}


void Player::AddPoints(int points){
  points_+=points;
}
