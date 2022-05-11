#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;
namespace coup{
    class Contessa: public Player
    {
    private:
        /* data */
    public:
        Contessa(Game &g1,string const &name);
        ~Contessa();
        static void block(Assassin &p);
        static void block(Player &p);      
        string role();
    };
    
    
}