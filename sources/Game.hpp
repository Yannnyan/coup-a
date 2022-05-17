#ifndef GAME_HPP_
#define GAME_HPP_
// #include "Player.hpp"

namespace coup
{
    class Player;
};
#include <string>
#include <vector>
#include <tuple>


namespace coup
{
    #define MAX_PLAYERS 6
    class Game
    {
        
        private:
            // list of names of the playing characters
            std::vector<Player *> _players;
            std::vector<Player *> _dead_players;
            /**
             * @brief This vector holds tuples of the source player, dest player ,adn operation number and the int that associated to the operation
             *  when a player wants to commit an action that can be blocked my another player it goes into this vector
             *  and then when a player wants to block that operation, the game tries to find the blocked operation here
             *  if not then an exception will be thrown.
             */
            std::vector<std::tuple<Player *, Player *, int, int>> _operations;
            // the name of the current player's turn
            int _player_turn;
            bool started;
        public:
            // constructors
            Game();
            // geters and settern
            // this functions increments the current player by one
            void make_turn();
            // returns the player which is currently playing the game
            Player * current_playing();
            //returns the name of the player to play next
            std::string turn();
            // returns who is the winner of the game.
            // if the game is still in progress, then throw exception.
            std::string winner();
            // returns a vector of strings which contains the names of the players in the game
            std::vector<std::string> players();
            /**
             * @brief join a player into the gmae
             * 
             * @param player 
             */
            void join_player(Player * player);
            /**
             * @brief Check if this player is currently in game, throw exception if not
             * 
             * @param player the player mentioned.
             */
            void is_player_in_game(Player * player);
            /**
             * @brief removes the currently playing player operation from the operation list
             * now the player's action cannot be blocked anymore
             * 
             */
            void remove_current_player_operation();
            /**
             * @brief this functions constructs a tuple of 4 and adds it to the operation list if it's a valid operation
             *  and a valid player that tries to add an operation
             * 
             * 
             * 
             * @param source the callingp player
             * @param target the target player
             * @param operation the operation to be executed on the target player or on the calling player depends
             * @param amount the amount to be transfered or stolen from if the operation is captain or ambassador
             */
            std::tuple<Player *, Player *, int ,int> remove_player_operation(Player * player);
            /**
             * @brief Get the operation object
             * 
             * @param player 
             * @return tuple<Player *, Player *, int ,int > 
             */
            std::tuple<Player *, Player *, int ,int > get_operation(Player * player);
            /**
             * @brief adds an operation to the list
             * 
             * @param source 
             * @param target 
             * @param operation 
             * @param amount 
             */
            void add_operation(Player * source, Player * target, int operation, int amount);
            /**
             * @brief removes the player from the game
             * 
             * @param player 
             */
            void vanish(Player * player);
            /**
             * @brief This function revives player from the dead player vector into the playing players vector
             * 
             * @param player the argument player
             */
            void revive(Player * player);
            /**
             * @brief the assassin kills a player sends him to the dead_players list
             * 
             * @param target is the target player 
             */
            void kill(Player * source, Player * target);
            /**
             * @brief should print out all the current operations.
             * 
             */
            void check_game_started();
            void print_operations();
    };      
}




#endif
