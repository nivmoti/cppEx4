#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include"Player.hpp"
using namespace std;
namespace coup{
    class Duke : public Player
    {
    private:
        /* data */
    public:
        Duke(Game &g1,string const &name);
        ~Duke();
        void tax();
        static void block(Player &d);
        string role();
    };
    
}