#include "Duke.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <string>

coup::Duke::Duke(coup::Game & game, std::string name) : Player(game, name)
{
    
}

void coup::Duke::tax()
{

}
// The duke can block forein_aid from a player
void coup::Duke::block(Player & player)
{
    
}

