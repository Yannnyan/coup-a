#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Game.hpp"
#include <string>

namespace coup
{
    #define COUP_COINS 7
    #define ASSASSIN_COUP_COINS 3
    #define MAX_COINS_BEF_COUP 10
    // A player hold the coins and the role of the player
    // A player must coup if he holds 10 coins at least.
    // ways to get income: income, forein_aid, transfer, steal, tax, 
    class Player
    {
        protected:
            int _coins;
            std::string _name;
            std::string _role;
            Game & _game;
        public:
            // constructors
            Player(Game &game, std::string name);
            // getters setters
            std::string getName() const;
            // gain 1 coin with no limitations.
            void income();
            // gain 2 coins 
            // check if a command hasn't been instructed before that blocks the operation and the turn if tried to
            void foreign_aid();
            // a player needs 7 coins to coup other player
            // player index must be valid and not sure if to use index
            virtual void coup(Player & player_index);
            // prints the player's role
            std::string role() const;
            // prints the amount of money the player holds
            int coins() const;
            /**
             * @brief check if in the current game this is this player's turn
             * 
             */
            void check_myturn();
            /**
             * @brief Decreases the amount of coins this player has by c
             * 
             * @param c 
             */
            void decrease_coins(int c);
            /**
             * @brief increases the amount of coins this player has by c
             * 
             * @param c 
             */
            void increase_coins(int c);
            void check_coins() const;
    };
}

#endif



