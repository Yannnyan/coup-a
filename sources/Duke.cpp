#include "Duke.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <tuple>
#include "props.hpp"

using namespace std;
using namespace coup;

coup::Duke::Duke(coup::Game & game, std::string name) : Player(game, move(name))
{
    this->_role = "Duke";
}

void coup::Duke::tax()
{
    this->_game.check_game_started();
    check_myturn();
    check_coins();
    this->_game.is_player_in_game(this);
    this->_coins += 3;
    this->_game.make_turn();
}
// The duke can block forein_aid from a player
void coup::Duke::block(Player & player)
{  
    this->_game.check_game_started();
    this->_game.is_player_in_game(this);
    tuple<Player *, Player *, int ,int > tup = this->_game.get_operation(&player);
    if(get<2>(tup) == enums::blocked_operations::Foreign_Aid)
    {  
        this->_game.remove_player_operation(&player);
        if(player.coins() == 0)
        {
            return;
        }
        if (player.coins() == 1)
        {
            player.decrease_coins(1);
        }
        else
        {
            player.decrease_coins(2);
        }
    }
    else
    {
        throw(invalid_argument("the player has not made a foreign aid."));

    }

}

