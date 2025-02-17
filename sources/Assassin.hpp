#ifndef ASSASSIN_HPP_
#define ASSASSIN_HPP_

#include "Player.hpp"
#include "Game.hpp"
#include <string>


namespace coup
{
    class Assassin : public Player
    {
        private:
        public:
            Assassin(Game & game, std::string name);
            // check if someone blocks the assassin from assassinating someone.
            // if someone is protected then return the player back to the game.
            virtual void coup(Player & index_player);
            
    };
}



#endif


