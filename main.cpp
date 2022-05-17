#include "sources/Player.hpp"
#include "sources/Game.hpp"
#include "sources/Assassin.hpp"
#include "sources/Captain.hpp"
#include "sources/Contessa.hpp"
#include "sources/Duke.hpp"
#include "sources/Ambassador.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace coup;

int main()
{
    Game scenario1;
    Duke PlayerONE{scenario1, "Player ONE"};
	Assassin PlayerTWO{scenario1, "Player TWO"};
	Duke PlayerTHREE{scenario1, "Player THREE"};
	Contessa PlayerFOUR{scenario1, "Player FOUR"};
    vector<Player*> Players = {&PlayerONE, &PlayerTWO, &PlayerTHREE, &PlayerFOUR};
    for(int i=0; i< 3; i++)
    for(Player * p : Players)
    {
            p->income();
    }
    PlayerONE.foreign_aid();
    scenario1.print_operations();
    PlayerTHREE.block(PlayerONE);
    cout << PlayerONE.coins() << endl;
    PlayerTWO.coup(PlayerONE);
    cout << PlayerTWO.coins() << endl;
    return 0;
}