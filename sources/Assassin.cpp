#include "Assassin.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <string>

using namespace std;
using namespace coup;

coup::Assassin::Assassin(Game & game, string name) : Player(game, move(name))
{
    this->_role = "Assassin";
}

void coup::Assassin::coup(Player & player) 
{
    this->_game.check_game_started();
    this->check_myturn();
    this->_game.is_player_in_game(this);
    this->_game.is_player_in_game(&player);
    if(this->_coins >= COUP_COINS)
    {
        this->_coins -= COUP_COINS;
        this->_game.vanish(&player);
        this->_game.make_turn();
        return;
    }
    if(this->_coins < ASSASSIN_COUP_COINS)
    {
        throw(invalid_argument("not enough coins as assassin to coup a player"));
    }
    this->_coins -= ASSASSIN_COUP_COINS;
    this->_game.kill(this, &player);
    this->_game.make_turn();
}

