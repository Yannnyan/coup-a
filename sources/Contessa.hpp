#ifndef CONTESSA_HPP_
#define CONTESSA_HPP_

#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup
{
    class Contessa : public Player
    {
        private:
        public:
            // constructors
            Contessa(Game &game, std::string name);

            // contessa will block an assassin from couping player.
            void block(Player &assassin);
    };
}

#endif
