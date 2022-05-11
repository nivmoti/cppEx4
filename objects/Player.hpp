#pragma once
#include "Game.hpp"
namespace coup
{
    class Player
    {
    private:
    Game ga;
    string nam;
    int money=0;    

    public:
        Player(Game const &g1,string const &name);
        ~Player();
        void income();
        void foreign_aid();
        void block(Player const &d);
        static int coins();
        void coup(Player const &to);
        static string role();
    };
    
   
    
} // namespace coup