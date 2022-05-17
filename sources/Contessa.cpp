#include "Contessa.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
#include "Game.hpp"
#include <tuple>


using namespace std;
using namespace coup;

coup::Contessa::Contessa(Game & game, string name) : Player(game, move(name))
{
    this->_role = "Contessa";
}

void coup::Contessa::block(Player &assassin)
{
    this->_game.check_game_started();
    if(dynamic_cast<Assassin *> (&assassin) == nullptr)
    {
        throw(invalid_argument("player given in the argument is not an assassin"));
    }
    this->_game.is_player_in_game(&assassin);
    this->_game.is_player_in_game(this);
    tuple<Player *, Player *, int ,int> tup = this->_game.remove_player_operation(&assassin);
    this->_game.revive(get<1>(tup));
}

