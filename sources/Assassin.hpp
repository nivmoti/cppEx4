#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
#include <stack>
using namespace std;
namespace coup{
    class Assassin : public Player
    {
    private:
    public:
        bool canbebockedby=false;
        Assassin(Game &g1,string const &name);
        ~Assassin();
        void coup(Player const &to);
        void income();
        void foreign_aid();
        string role();
        void giveback();
        void kill();
        
    };
    
    
}