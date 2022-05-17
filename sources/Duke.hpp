#ifndef DUKE_HPP_
#define DUKE_HPP_

#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup
{
    class Duke : public Player
    {
        private:

        public:
            // constructors
            Duke(Game & game, std::string name);
            // the duke take tax of 3 coins from the bank
            void tax();
            // The duke can block forein_aid from a player
            void block(Player &player);

    }; 
}

#endif

