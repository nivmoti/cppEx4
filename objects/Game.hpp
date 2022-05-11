#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <queue>
using namespace std;
namespace coup{
    class Game
    {
    private:
    int tur;
        
    public:
        vector<string> ingame;
        Game();
        ~Game();
        vector<string> players();
        string turn();
        string winner();
        void Add(string const name);
        void Nexturn();
    };
    
    
    
    
}