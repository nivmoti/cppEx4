
#include"Game.hpp"
using namespace coup;
    Game::Game(/* args */)
    {
        tur=0;
        this->finturn="";
    }
    
    Game::~Game()
    {
        ingame.clear();
    }
    vector<string> Game::players() const
    {
        vector<string> names; 
        for (unsigned long i = 0; i < this->ingame.size(); i++)
        {
            if(this->ingame.at(i)!=this->deadtemp){names.push_back(this->ingame.at(i));}
        }
        
       return names;
    }
    string Game::turn()
    {
        return ingame.at((unsigned long)tur);
    }
    string Game::winner() const{
        vector<string> win=this->players();
        if(win.size()>1){throw std::out_of_range("the game is not finished");}
         if(!(this->stated)){throw std::out_of_range("game not started");}
         return win.at(0);
    }
    void Game::Nexturn(){
            tur++;
            if(tur>=this->ingame.size()){tur=0;}
            while (this->ingame.at((unsigned long)tur)==this->deadtemp)
            {
                if(tur+1>=this->ingame.size()){tur=0;}
                else{tur++;}
            }
            
        }
    