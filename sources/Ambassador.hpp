#ifndef AMBASSADOR_HPP_
#define AMBASSADOR_HPP_

#include "Player.hpp"
#include "Game.hpp"
#include <string>


namespace coup
{
    class Ambassador : public Player
    {
        private:
        public:
            Ambassador(Game & game, std::string name);
            // transfers one coin from source to dest
            void transfer(Player &source, Player & dest);
            // function name is not current waiting to change it
            // this function supposed to block the Captain from stealing coins from other players.
            void block(Player & source);
    };

}

#endif


