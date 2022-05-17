#include "Player.hpp"
#include "Game.hpp"
#include "props.hpp"

using namespace std;
using namespace coup;

coup::Player::Player(Game & game, string _name) : _game(game), _name(move(_name)), _coins(0)
{
    this->_game.join_player(this);
}

std::string coup::Player::getName() const
{
    return this->_name;
}
// gain 1 coin with no limitations.
void coup::Player::income()
{
    this->_game.check_game_started();
    check_myturn();
    check_coins();
    this->_game.is_player_in_game(this);
    this->_coins+=1;
    this->_game.make_turn();
}
// gain 2 coins 
// check if a command hasn't been instructed before that blocks the operation and the turn if tried to
void coup::Player::foreign_aid()
{
    this->_game.check_game_started();
    check_myturn();
    check_coins();
    this->_game.is_player_in_game(this);
    this->_coins+=2;
    this->_game.add_operation(this, nullptr, enums::blocked_operations::Foreign_Aid, 0);
    this->_game.make_turn();

}
// a player needs 7 coins to coup other player
// player index must be valid and not sure if to use index
void coup::Player::coup(Player &player)
{
    this->_game.check_game_started();
    check_myturn();
    this->_game.is_player_in_game(&player);
    this->_game.is_player_in_game(this);
    if(this->_coins < COUP_COINS)
    {
        throw(invalid_argument("not enough coins to coup a player."));
    }
    this->_coins -= COUP_COINS;
    this->_game.vanish(&player);
    this->_game.make_turn();
}
// prints the player's role
std::string coup::Player::role() const
{
    return this->_role;
}
// prints the amount of money the player holds
int coup::Player::coins() const
{
    return this->_coins;
}

void coup::Player::check_myturn()
{
    if(this->_game.current_playing() != this)
    {
        throw(invalid_argument("wrong player's turn."));
    }
}


void coup::Player::decrease_coins(int c)
{
    if(this->_coins - c < 0)
    {
        throw(invalid_argument("amount of coins cannot be negative."));
    }
    this->_coins-=c;
}
void coup::Player::increase_coins(int c)
{
    this->_coins+=c;
}

void coup::Player::check_coins() const
{
    if(this->_coins >= MAX_COINS_BEF_COUP)
    {
        throw(invalid_argument("cannot do operation that is not coup when having more than 10 coins."));
    }
}
