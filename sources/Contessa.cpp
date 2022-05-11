#include "Contessa.hpp"
using namespace coup;
Contessa::Contessa(Game &g1,string const &name) : Player(g1,name){
    

}
Contessa::~Contessa(){
    
}
void Contessa::block(Assassin &p){
    if(p.canbebockedby){
        p.giveback();
    }
    else{throw std::out_of_range("cannot be blocked");}

}
string Contessa::role(){
    return "Contessa";
}
void Contessa::block(Player &P){
    throw std::out_of_range("cannot be blocked by Contessa");
}
