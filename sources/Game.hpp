#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
namespace coup{
    class Game
    {
    private:
        
    public:
        int tur;
        bool stated=false;
        vector<string> ingame ;
        string deadtemp;
        string finturn;
        Game();
        ~Game();
        vector<string>players() const;
        string turn();
        string winner() const;
        void Nexturn();
    };
    
    
    
    
}