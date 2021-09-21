#include "player.h"

#include <vector> //std::erase, std::begin/end
#include <algorithm> // std::remove
#include "board.h"  //board
#include <iostream> //std::cout std::cin
Player::Player(): name_(0),pieces_({}),points_(0){}

Player::Player(const char* name,std::vector<Piece*> pieces)
:name_(name),pieces_(pieces),points_(0){}



void Player::AddPoints(int points){
  points_+=points;
}

void Player::RemovePiece(Piece* piece)
{
  pieces_.erase(std::remove(std::begin(pieces_),std::end(pieces_) ,piece)
  ,std::end(pieces_));
}

void Player::Init(Board board)
{
  std::cout << "Enter name\n>";
  std::cin >> name_;
}

//---------Getters and Setters--------/
std::vector<Piece*> Player::GetPieces() const noexcept{return pieces_;}
int Player::GetPoints() const noexcept {return points_;}
const char* Player::GetName() const noexcept {return name_;}
void Player::SetName(const char* newName){name_ = newName;}
void Player::SetPieces(std::vector<Piece*> pieces){pieces_ = pieces;}
