#include "Player.hpp"
#include "Game.hpp"
#include <string>



namespace coup
{
    class Captain : public Player
    {
        private:
        public:
            Captain(Game & game, std::string name) : Player(game, name){}
            // steals 2 coins from another player 
            // this operation can be blocked by the ambassador
            void steal(Player & player);
            void block(Player & player);

    };


}



