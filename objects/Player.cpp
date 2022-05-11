#include "Player.hpp"
using namespace coup;
Player::Player(Game const &g1,string const &name)
{
    this->ga=g1;
    this->nam=name;
    this->ga.ingame.push_back(name);
}

Player::~Player()
{
}
void Player::income()
{
    
}
void Player::block(Player const &d){

}
void Player::foreign_aid()
{
}
int Player::coins()
{
    return 1;
}
void Player::coup(Player const &to)
{
}
string Player::role(){
return "";
}