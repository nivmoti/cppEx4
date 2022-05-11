#include "Ambassador.hpp"
using namespace coup;
void Ambassador::transfer(Player &from,Player &to){
    if((*this->ga).players().size()==1){throw std::out_of_range("not the amout of players we allowed to play");}
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    if(from.Player::coins()<=0){throw std::out_of_range("cant steal from a player with 0 coins");}
    if(this->coins()>=Player::COUPMOSY){throw std::out_of_range("you have to coup");}
    this->canbebockedby=true;
    from.change(from.coins()-1);
    to.change(to.coins()+1);
    (*this->ga).Nexturn();    
}
Ambassador::Ambassador(Game &g1,string const &name):Player(g1,name){
    this->canbebockedby=false;

}
Ambassador::~Ambassador(){
    

}
string Ambassador::role(){
    return "Ambassador";
}
void Ambassador::block(Captain &d){
    if(d.role()!="Captain"){throw std::out_of_range("cant use on that Player");}
    if(d.canbeblockby){
        d.giveback();
    }
        
}
void Ambassador::block(Player &d){
    throw std::out_of_range("cannot be blocked by Ambassador");
}

