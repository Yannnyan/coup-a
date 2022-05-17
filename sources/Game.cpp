#include "Game.hpp"
#include <string>
#include "Player.hpp"
#include <stdexcept>
#include "props.hpp"
#include <tuple>
#include <iostream>

using namespace std;
using namespace coup;


coup::Game::Game()
{
    this->_dead_players = vector<Player *>();
    this->_players = vector<Player *>();
    this->_operations = vector<tuple<Player *, Player *, int ,int>>();
    this->_player_turn = 0;
    this->started = false;

}
void coup::Game::make_turn()
{
    this->_player_turn = this->_player_turn % (int)this->_players.size();
    this->_player_turn +=1;
    this-> _player_turn = this->_player_turn % (int)this->_players.size();
    remove_current_player_operation();
}
Player * coup::Game::current_playing()
{
    return this->_players.at((size_t)this->_player_turn);
}

std::string coup::Game::turn()
{
    return this->_players.at((size_t)this->_player_turn)->getName() + to_string(this->_player_turn);
}

std::string coup::Game::winner()
{
    if (this->players().empty() || !started)
    {
        throw(invalid_argument("game has not started yet"));
    }
    if(this->players().size() != 1)
    {
        throw(invalid_argument("game has not ender yet"));
    }
    // return the winner
    return players().at(0);

}

std::vector<std::string> coup::Game::players()
{
    vector<string> names;
    for(Player * p: this->_players)
    {
        names.push_back(p->getName());
    }
    return names;
}

void coup::Game::join_player(Player * player)
{
    if(this->started)
    {
        throw(invalid_argument("cannot join a player when the game has already started."));
    }
    if(this->_players.size() == MAX_PLAYERS)
    {
        throw(invalid_argument("cannot add more than 6 players into the game."));
    }
    this->_players.push_back(player);
}

void coup::Game::is_player_in_game(Player * player)
{
    vector<Player *>::iterator iter = this->_players.begin();
    vector<Player *>::iterator end = this->_players.end();
    while(iter != end)
    {
        if((*iter) == player)
        {
            return;
        }
        iter++;
    }
    throw(invalid_argument("player is not in game."));
}

std::tuple<Player *, Player *, int ,int > coup::Game::get_operation(Player * player)
{
    vector<tuple<Player *, Player *, int , int>>::iterator iter = this->_operations.begin();
    vector<tuple<Player *, Player *, int , int>>::iterator end = this->_operations.end();
    while(iter != end)
    {
        if(get<0>(*iter) == player)
        {
            return (*iter);
        }
        iter++;
    }
    throw(invalid_argument("cannot find the player in the operations list"));
}

void coup::Game::remove_current_player_operation()
{
    vector<tuple<Player *, Player *, int , int>>::iterator iter = this->_operations.begin();
    vector<tuple<Player *, Player *, int , int>>::iterator end = this->_operations.end();
    while(iter != end)
    {
        if(get<0>(*iter) == this->_players.at((size_t)this->_player_turn))
        {
            if(get<3>(*iter) == enums::blocked_operations::Assassin_coup)
            {

            }
            this->_operations.erase(iter);
            this->_operations.shrink_to_fit();
            break;
        }
        iter++;
    }

}
tuple<Player *, Player *, int ,int> coup::Game::remove_player_operation(Player * player)
{
    vector<tuple<Player *, Player *, int , int>>::iterator iter = this->_operations.begin();
    vector<tuple<Player *, Player *, int , int>>::iterator end = this->_operations.end();
    tuple<Player *, Player *, int ,int> ret;
    while(iter != end)
    {
        if(get<0>(*iter) == player)
        {
            ret = (*iter);
            this->_operations.erase(iter);
            this->_operations.shrink_to_fit();
            return ret;
        }
        iter++;
    }
    throw(invalid_argument("Cannot remove a player that did not do any operation from the list."));
}

void coup::Game::add_operation(Player * source, Player * target = nullptr, int operation = -1, int amount = 0)
{
    // check valid parameters
    if (operation != enums::blocked_operations::Assassin_coup &&
    operation != enums::blocked_operations::Captain_Steal &&
    operation != enums::blocked_operations::Foreign_Aid)
    {
        throw(invalid_argument("cannot do this operation its not found in the blocked operation section."));
    }
    int below_zero = 0;
    int above_two = 2;
    if (amount < below_zero || amount > above_two)
    {
        throw(invalid_argument("No such amount can be entered to an operation."));
    }
    this->is_player_in_game(source);
    if(target != nullptr)
    {
        this->is_player_in_game(target);
    }
    // finnally add the operation to the list
    this->_operations.push_back(tuple<Player *, Player *, int ,int >(source,target,operation,amount));
}

void coup::Game::vanish(Player * player)
{
    is_player_in_game(player);
    int index = 0;
    vector<Player *>::iterator iter = this->_players.begin();
    vector<Player *>::iterator end = this->_players.end();
    while(iter != end)
    {
        if((*iter) == player)
        {
            if(index <= this->_player_turn)
            {
                this->_player_turn -=1;
            }
            this->_players.erase(iter);
            this->_players.shrink_to_fit();
        }
        index++;
        iter++;
    }
}


void coup::Game::revive(Player * player)
{
    vector<Player *>::iterator iter = this->_dead_players.begin();
    vector<Player *>::iterator end = this->_dead_players.end();
    while(iter != end)
    {
        if((*iter) == player)
        {
            this->_players.insert(this->_players.begin(), *iter);
            // this->_players.push_back((*iter));
            this->_player_turn +=1;
            this->_dead_players.erase(iter);
            this->_dead_players.shrink_to_fit();
            return;
        }
        iter++;
    }
    throw(invalid_argument("cannot find the specified player to revive."));
}

void coup::Game::kill(Player * source, Player * target)
{
    is_player_in_game(target);
    this->_dead_players.push_back(target);
    this->add_operation(source, target, enums::blocked_operations::Assassin_coup, 0);
    this->vanish(target);
}

void coup::Game::print_operations()
{
    for(size_t i=0; i<this->_operations.size(); i++)
    {
        cout << "source is : " + get<0>(this->_operations.at(i))->getName() +
         
        " operation is : " + to_string(get<2>(this->_operations.at(i))) + 
        " value is : " + to_string(get<3>(this-> _operations.at(i))) << endl;
    }
}

void coup::Game::check_game_started()
{
    if(this->_players.size() >= 2)
    {
        this->started = true;
    }
    if(!this->started)
    {
        throw(invalid_argument("Game has not started yet."));
    }
}


