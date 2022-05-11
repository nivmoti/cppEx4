#include "Assassin.hpp"
using namespace coup;
Assassin::Assassin(Game &g1,string const &name) : Player(g1,name){
    this->canbebockedby=false;
    

}
Assassin::~Assassin(){
    
}
void Assassin::kill(){
    if(this->canbeblock){
        string namedead=(*this->ga).deadtemp;
        (*this->ga).ingame.erase(std::remove((*this->ga).ingame.begin(), (*this->ga).ingame.end(), namedead), (*this->ga).ingame.end());
        this->canbebockedby=false;
        (*this->ga).deadtemp="";
       
    }
}
void Assassin::coup(Player const &to){
    if((*this->ga).players().size()==1){throw std::out_of_range("not the amout of players we allowed to play");}
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    this->kill();
    if(this->coins()<Player::MAXCOINS){
        if(this->coins()<3){throw std::out_of_range("not enough money");}
        auto it = find((*this->ga).ingame.begin(), (*this->ga).ingame.end(), to.nam);
        if(it==(*this->ga).ingame.end()){throw std::out_of_range("user not found");}
        (*this->ga).deadtemp=to.nam;
        this->canbebockedby=true;
        this->change(this->coins()-3);
        if((*this->ga).ingame.size()==2){
            this->kill();
        }
        it = find((*this->ga).ingame.begin(), (*this->ga).ingame.end(), this->nam);
        (*this->ga).tur=it-(*this->ga).ingame.begin();
        (*this->ga).Nexturn();
        
    }
    else{
        Player::coup(to);
    }

}
string Assassin::role(){
    return "Assassin";
}
void Assassin::giveback(){
    (*this->ga).deadtemp="";
    this->canbebockedby=false;



}
void Assassin::income(){
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    this->kill();
    Player::income();

}
void Assassin::foreign_aid(){
    if((*this->ga).turn()!=this->nam){throw std::out_of_range("not your turn!");}
    this->kill();
    Player::foreign_aid();
}
