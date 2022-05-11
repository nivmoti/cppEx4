#include "Duke.hpp"
using namespace coup;
Duke::Duke(Game &g1,string const &name) : Player(g1,name){
    
}
Duke::~Duke()
{
}
void Duke::tax()
{
    if(((*this->ga).players().size()==1)||((*this->ga).players().size()>Player::MAXPLAYERS)){throw std::out_of_range("not the amout of players we allowed to play");}
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    if(this->coins()>=Player::COUPMOSY){throw std::out_of_range("you have to coup");}
    this->change(this->coins()+3);
    (*this->ga).Nexturn();


}
void Duke::block(Player &d){
    d.giveback();
}
string Duke::role(){
    return "Duke";
}