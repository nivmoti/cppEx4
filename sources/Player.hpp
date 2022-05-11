#pragma once
#include "Game.hpp"
namespace coup
{
    class Player
    {
   
    private:
    
    int money; 

    public:
        Game *ga;
        bool canbeblock;
        string nam;
        string job;
        int const MAXCOINS = 7;
        int const MAXPLAYERS = 6;
        int const COUPMOSY=10;
        Player(Game  &g1,string const &name);
        ~Player();
        void income();
        void foreign_aid();
        static void block(Player const &d);
        int  coins() const;
        void coup(Player const &to);
        virtual string role();
        void  change(int num);
        void giveback();

    };
    
   
    
} // namespace coup