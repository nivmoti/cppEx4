#include "Player.hpp"
using namespace coup;
Player::Player(Game &g1,string const &name)
{
    
    this->ga=&g1;
    this->nam=name;
    this->canbeblock=false;
    this->money=0;
    if((*this->ga).stated){throw std::out_of_range("game started already");}
    if((*this->ga).players().size()<Player::MAXPLAYERS){
    (*this->ga).ingame.push_back(this->nam);
    }
    else{throw std::out_of_range("to many player");}
    
}

Player::~Player()
{
}
void Player::income()
{

    if(((*this->ga).players().size()==1)){throw std::out_of_range("not the amout of players we allowed to play");}
    (*this->ga).stated=true;
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    if(this->money>=Player::COUPMOSY){throw std::out_of_range("you have to coup");}
   this->money++;
   this->canbeblock=false;
   (*this->ga).Nexturn();

}
void Player::block(Player const &d){

}
void Player::foreign_aid()
{
    
    if((*this->ga).players().size()==1){throw std::out_of_range("not the amout of players we allowed to play");}
    (*this->ga).stated=true;
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    if(this->money>=Player::COUPMOSY){throw std::out_of_range("you have to coup");}
    this->money=this->money+2;
    this->canbeblock=true;
    (*this->ga).Nexturn();
}
int Player::coins() const
{
    int const x=this->money;
    return x;
    
}
void Player::coup(Player const &to)
{
    if((*this->ga).players().size()==1){throw std::out_of_range("not the amout of players we allowed to play");}
    (*this->ga).stated=true;
    if(money<Player::MAXCOINS){
        throw std::out_of_range("not enough money");
    }
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    auto it = find((*this->ga).ingame.begin(), (*this->ga).ingame.end(), to.nam);
    if(it==(*this->ga).ingame.end()){throw std::out_of_range("user not found");}
    this->money=this->money-Player::MAXCOINS;
    (*this->ga).ingame.erase(std::remove((*this->ga).ingame.begin(), (*this->ga).ingame.end(), to.nam), (*this->ga).ingame.end());
    it = find((*this->ga).ingame.begin(), (*this->ga).ingame.end(), this->nam);
    (*this->ga).tur=it-(*this->ga).ingame.begin();
    
    (*this->ga).Nexturn();

    this->canbeblock=false;
    


}
string Player::role()
{
    return this->job;
}
void Player::change(int num) {
    this->money=num;
}
void Player::giveback(){
    if(this->canbeblock){
    this->money=this->money-2;
    this->canbeblock=false;
    }
    else{throw std::out_of_range("cannot be blocked now");}


}