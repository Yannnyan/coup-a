
#include "role.hpp"
#include "Game.hpp"


namespace coup
{
    // A player hold the coins and the role of the player
    // A player must coup if he holds 10 coins at least.
    // ways to get income: income, forein_aid, transfer, steal, tax, 
    class Player
    {
        private:
            long coins;
            coup::role player_role;
            int player_index;
            std::string name;
        public:
            // constructors
            Player(Game game, std::string name);
            // getters setters
            std::string getName();
            // gain 1 coin with no limitations.
            void income();
            // gain 2 coins 
            // check if a command hasn't been instructed before that blocks the operation and the turn if tried to
            void forein_aid();
            // a player needs 7 coins to coup other player
            // player index must be valid and not sure if to use index
            void coup(Player player_index);
            // prints the player's role
            void role();
            // prints the amount of money the player holds
            long coins();
            // checks if this is equal to the argument player by the player's index
            bool operator==(Player player);

    };
}





