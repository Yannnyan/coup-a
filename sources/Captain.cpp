#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include "props.hpp"
#include <stdexcept>
#include <tuple>

using namespace std;
using namespace coup;

coup::Captain::Captain(Game & game, string name) : Player(game, move(name))
{
    this->_role = "Captain";
}
void coup::Captain::steal(Player &player)
{
    this->_game.check_game_started();
    this->_game.is_player_in_game(this);
    this->_game.is_player_in_game(&player);
    this->check_myturn();
    check_coins();
    if(player.coins() == 0)
    {
        return;
    }
    if (player.coins() == 1)
    {
        player.decrease_coins(1);
        this->increase_coins(1);
        this->_game.add_operation(this, &player, enums::blocked_operations::Captain_Steal, 1);
    }
    else{
        player.decrease_coins(2);
        this->increase_coins(2);
        this->_game.add_operation(this, &player, enums::blocked_operations::Captain_Steal, 2);
    }
    this->_game.make_turn();
}
void coup::Captain::block(Player &player)
{
    this->_game.check_game_started();
    if(dynamic_cast<Captain *>(&player) == nullptr)
    {
        throw(invalid_argument("cannot block non captain player."));
    }
    tuple<Player *, Player *, int, int > tup = this->_game.remove_player_operation(&player);
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



