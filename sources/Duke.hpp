#include "Player.hpp"


namespace coup
{
    class Duke : coup::Player
    {
        private:

        public:
            // the duke take tax of 3 coins from the bank
            void tax();
            // The duke can block forein_aid from a player
            void block(Player player);

    }; 
}



