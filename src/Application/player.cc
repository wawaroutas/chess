#include "player.h"

#include <vector> //std::erase, std::begin/end
#include <algorithm> // std::remove
#include <iostream> // std::cin std::cout std::getline()
#include <sstream> // std::stringstream
Player::Player(): name_(""),pieces_({}),points_(0){
  pieces_.reserve(16);

}

Player::Player(std::string name,std::vector<Piece*> pieces)
:name_(name),pieces_(pieces),points_(0){}



void Player::AddPoints(int points){
  points_+=points;
}

void Player::RemovePiece(Piece* piece)
{
  pieces_.erase(std::remove(std::begin(pieces_),std::end(pieces_) ,piece)
  ,std::end(pieces_));
}

void Player::Init(Board board,Color c)
{
  std::cout << "init player\n";
std::cout <<pieces_.capacity()<< " capacity of player pieces\n";
  SetPieces(board.GetPieces(c));
  std::cout <<pieces_.size()<< "size of player pieces\n";
  std::cout << "Enter your name\n>";
  std::cin >> name_;
  std::cout << "Welcome " << name_ <<
  "! You were assigned the " << c << "pieces\n";
}

void Player::MakeMove(Board board)
{
  std::string input,pos1,pos2;
  bool flag =true;
  while(flag)
  {
    std::cout << "Enter move to make in form FileRank -> FileRank:\n>";
    std::cin >> input;
    int pos = input.find("->");
    pos1 = input.substr(0,pos);
    pos2 = input.substr(pos+1,std::string::npos);
    Square from = board.square(pos1);
    Square to = board.square(pos2);
    flag = from.GetPiece()->MovePiece(board.square(pos2),board);
    if(!flag) std::cout << "Bad move\n";
  }
}

bool Player::operator==(const Player& other){
  return pieces_ == other.pieces_;
}
//---------Getters and Setters--------/
std::vector<Piece*> Player::GetPieces() const noexcept{return pieces_;}
int Player::GetPoints() const noexcept {return points_;}
std::string Player::GetName() const noexcept {return name_;}
void Player::SetName(std::string newName){name_ = newName;}
void Player::SetPieces(std::vector<Piece*> newPieces){
  for(Piece* piece : newPieces)
    pieces_.push_back(piece);
}
