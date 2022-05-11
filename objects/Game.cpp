
#include"Game.hpp"
using namespace coup;
    Game::Game(/* args */)
    {
        this->tur=0;
    }
    
    Game::~Game()
    {
        ingame.clear();
    }
    vector<string> Game::players()
    {
       return this->ingame;
    }
    string Game::turn()
    {
        return this->ingame[this->tur];
    }
    string Game::winner(){
        if(ingame.size()>1){throw std::out_of_range("the game is not finished");}
        else{
         
         return ingame.at(0);
        }
    }
    void Game::Add(string const name){
        this->ingame.push_back(name);
        
    }
    void Game::Nexturn(){
        if(this->tur+1==this->ingame.size()){
            tur=0;
        }
        else{
            tur++;
        }
    }