#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Captain : public Player
    {
    private:
        Player* stea;
    public:
        bool canbeblockby;
        Captain(Game &g1,string const &name);
        ~Captain();
        void steal(Player &from);
        void giveback();
        static void block(Captain  &d);
        static void block(Player  &d);
        void coup(Player const &to);
        void income();
        void foreign_aid();
        string role();
        
    };
    
}