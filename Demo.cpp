/**
 * Demo program for Coup exercise
 *
 * @author: Tal Zichlinsky
 * @since: 2022-02
 */

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {

	Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	vector<string> players = game_1.players();

	/*
		prints:
		Moshe
		Yossi
		Meirav
		Reut
		Gilad
	*/
	for(string name : players){
		cout << name << endl;
	}

	// prints Moshe
	cout << game_1.turn() << endl;

	// throws no exceptions
	duke.income();
	assassin.income();
	ambassador.income();
	captain.income();
	contessa.income();

	// throws exception, it is duke's turn now
	assassin.income();

	duke.income();
	assassin.foreign_aid();

	// throws exception, the last operation duke performed
	// is income, which cannot be blocked by any role
	captain.block(duke);

	cout << duke.coins() << endl; // prints 2
	cout << assassin.coins() << endl; // prints 3

	// throws exception, the last operation duke performed
	// is foreign aid, which cannot be blocked by contessa
	contessa.block(assassin);

	duke.block(assassin);
	cout << assassin.coins() << endl; // prints 1

	ambassador.transfer(duke, assassin); //transfers 1 coin from duke to assassin
	captain.foreign_aid();
	contessa.foreign_aid();

	duke.tax();
	assassin.income();
	ambassador.foreign_aid();
	captain.steal(contessa);
	contessa.foreign_aid();

	duke.tax();
	// no exception, assassin can coup with only 3 coins
	assassin.coup(duke);

	players = game_1.players();
	/*
		prints:
		Yossi
		Meirav
		Reut
		Gilad
	*/
	for (string name : players)
	{
		cout << name << endl;
	}

	contessa.block(assassin);

	players = game_1.players();
	/*
		prints:
		Yossi
		Meirav
		Reut
		Gilad
	*/
	for (string name : players)
	{
		cout << name << endl;
	}
}

