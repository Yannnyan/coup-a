#include "Player.hpp"




std::string coup::Player::getName() const
{
    return this->_name;
}
// gain 1 coin with no limitations.
void coup::Player::income()
{

}
// gain 2 coins 
// check if a command hasn't been instructed before that blocks the operation and the turn if tried to
void coup::Player::foreign_aid()
{

}
// a player needs 7 coins to coup other player
// player index must be valid and not sure if to use index
void coup::Player::coup(Player &player_index)
{

}
// prints the player's role
std::string coup::Player::role() const
{
    return "";
}
// prints the amount of money the player holds
int coup::Player::coins() const
{
    return this->_coins;
}
// checks if this is equal to the argument player by the player's index
bool coup::Player::operator==(Player & player)
{
    return false;
}