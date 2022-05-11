#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Captain.hpp"
using namespace std;
namespace coup{
    class Ambassador : public Player
    {
    private:
        // Game ga;
        // string nam;
        // int money; 
        // bool canbeblock;  
        
    public:
        bool canbebockedby=false;
        Ambassador(Game &g1,string const &name);
        ~Ambassador();
        void transfer(Player  &from,Player  &to);
        string role();
        static void block(Captain &d);
        static void block(Player &d);
        
    };
    
    
}