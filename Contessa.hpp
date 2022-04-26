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
            Contessa(Game &game, std::string name) : Player(game, name)
            {}

            // contessa will block an assassin from couping player.
            void block(Player &assassin);
    };
}

