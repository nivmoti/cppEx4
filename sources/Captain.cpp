#include "Captain.hpp"
using namespace coup;
Captain::Captain(Game &g1,string const &name) : Player(g1,name){
    this->canbeblockby=false;
    this->stea=NULL;

}

Captain::~Captain()
{
}

void Captain::steal(Player &from)
{
    if(((*this->ga).players().size()==1)||((*this->ga).players().size()>Player::MAXPLAYERS)){throw std::out_of_range("not the amout of players we allowed to play");}
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    if(this->coins()>=Player::COUPMOSY){throw std::out_of_range("you have to coup");}
    if(from.coins()==1){
        from.change(from.coins()-1);
        this->change(this->coins()+1);
        this->canbeblockby=true;
        this->stea=&from;
    }
    if(from.coins()>1){
    from.change(from.coins()-2);
    this->change(this->coins()+2);
    this->canbeblockby=true;
    this->stea=&from;
    
    }
    (*this->ga).Nexturn();


}
string Captain::role(){
    return "Captain";
}
void Captain::giveback(){
    if(this->canbeblockby)
    {
        this->change(this->coins()-2);
        (*this->stea).change((*this->stea).coins()+2);
        this->canbeblockby=false;
    }
    

}
void Captain::block(Player &d){
    throw std::out_of_range("cannot block this player");
}
void Captain::block(Captain &d){
    if(d.role()!="Captain"){throw std::out_of_range("cant use on that Player");}
    d.giveback();
    


}
void Captain::income(){
    Player::income();
    this->canbeblockby=false;
}
void Captain::foreign_aid(){
    Player::foreign_aid();
    this->canbeblockby=false;
}
void Captain::coup(Player const &to){
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    this->canbeblockby=false;
    Player::coup(to);
}