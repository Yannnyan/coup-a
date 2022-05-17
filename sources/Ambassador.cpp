#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <tuple>
#include <stdexcept>

using namespace std;
using namespace coup;

coup::Ambassador::Ambassador(Game & game, std::string name) : Player(game, move(name))
{
    this->_role = "Ambassador";
}

// transfers one coin from source to dest
void coup::Ambassador::transfer(Player & source, Player & dest)
{
    this->_game.check_game_started();
    this->_game.is_player_in_game(this);
    this->_game.is_player_in_game(&source);
    this->_game.is_player_in_game(&dest);
    this->check_myturn();
    check_coins();
    if(source.coins() == 0)
    {
        throw(invalid_argument("cannot transfer 0 coins."));
    }
    if(source.coins() >= 1)
    {
        source.decrease_coins(1);
        dest.increase_coins(1);
    }
    this->_game.make_turn();
    // else dont do anything the player doesn't have any coins
}
// function name is not current waiting to change it
// this function supposed to block the Captain from stealing coins from other players.
void coup::Ambassador::block(Player & source)
{
    this->_game.check_game_started();
    if(dynamic_cast<Captain *>(&source) == nullptr)
    {
        throw(invalid_argument("target is not poiting to a captain."));
    }
    tuple<Player *, Player *, int, int > tup = this->_game.remove_player_operation(&source);
    Player * source_captain = get<0>(tup);
    Player * target_player = get<1>(tup);
    int amount = get<3>(tup); 
    this->_game.is_player_in_game(source_captain);
    this->_game.is_player_in_game(target_player);
    if(source_captain->coins() == 0)
    {
        return;
    }
    if (source_captain->coins() >= amount)
    {
        source_captain->decrease_coins(amount);
        target_player->increase_coins(amount);
    }
    else
    {
        source_captain->decrease_coins(1);
        target_player->increase_coins(1);
    }
    
}




