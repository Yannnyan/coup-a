#pragma once
#include "Game.hpp"
#include "role.hpp"
#include <string>

namespace coup
{
    // A player hold the coins and the role of the player
    // A player must coup if he holds 10 coins at least.
    // ways to get income: income, forein_aid, transfer, steal, tax, 
    class Player
    {
        protected:
            int _coins;
            role _player_role;
            int _player_index;
            std::string _name;
        public:
            // constructors
            Player(Game game, std::string name)
            {
                
            }
            // getters setters
            std::string getName() const;
            // gain 1 coin with no limitations.
            void income();
            // gain 2 coins 
            // check if a command hasn't been instructed before that blocks the operation and the turn if tried to
            void foreign_aid();
            // a player needs 7 coins to coup other player
            // player index must be valid and not sure if to use index
            void coup(Player & player_index);
            // prints the player's role
            std::string role() const;
            // prints the amount of money the player holds
            int coins() const;
            // checks if this is equal to the argument player by the player's index
            bool operator==(Player & player);

    };
}





