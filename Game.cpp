#include "Game.hpp"
#include <string>




void coup::Game::set_turn(std::string & player)
{
    
}
//returns the name of the player to play next
std::string coup::Game::turn()
{
    return this->_player_turn;
}
// returns who is the winner of the game.
// if the game is still in progress, then throw exception.
std::string coup::Game::winner()
{
    std::vector<std::string> str = this->_players;
    return str.at(0);
}
// returns a vector of strings which contains the names of the players in the game
std::vector<std::string> &  coup::Game::players()
{
    return this->_players;
}


