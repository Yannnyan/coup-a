#include "doctest.h"
#include "Player.hpp"
#include "Game.hpp"
#include "role.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"
#include "Duke.hpp"
#include "Contessa.hpp"

using namespace std;
using namespace coup;

Game game1;


TEST_CASE("Player")
{
    Duke duke{game1, "Michael Jackson"};
    CHECK(duke.coins() == 0);
    duke.income();
    CHECK(duke.coins() == 1);
    duke.income();
    CHECK(duke.coins() == 2);
    duke.foreign_aid();
    CHECK(duke.coins() == 4);
    CHECK(duke.role().compare("Duke"));
    duke.tax();
    CHECK(duke.coins() == 7);

    
}
TEST_CASE("Ambassador")
{
    Ambassador amb{game1, "Brock lesner"};
    Assassin assassin{game1, "creed"};
    Duke duke{game1,"edward"};
    // ambassador blocks non captain players
    CHECK_THROWS(amb.block(assassin));
    CHECK_THROWS(amb.block(duke));
    // assassin and duke both have 0 coins
    // no player can have negative coins 
    CHECK_THROWS(amb.transfer(assassin, duke));


}
TEST_CASE("Assassin")
{
    Game game2;
    Assassin assassin{game2, "loop choke"};
    Duke duke{game2, "duka"};
    assassin.foreign_aid();
    assassin.income();
    CHECK_NOTHROW(assassin.coup(duke));
    CHECK(game2.players().size() == 1);
    Contessa contessa{game2, "amona liza"};
    contessa.block(assassin);
    CHECK_NOTHROW(assassin.coup(contessa));
    CHECK(game2.players().size() == 2);
}
TEST_CASE("Duke")
{
    Game game2;
    Duke duke{game2, "insert name"};
    duke.tax();
    CHECK(duke.coins() == 3);
    Assassin assassin{game2, "rush b"};
    duke.block(assassin);
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK(assassin.coins() == 0);
}
TEST_CASE("Contessa")
{
    Game game2;
    Contessa contessa{game2, "intel core i5"};
    Assassin assassin{game2, "linux"};
    Duke duke{game2, "excersice 5 in operating systems"};
    contessa.block(assassin);
    assassin.foreign_aid();
    assassin.income();
    assassin.coup(duke);
    CHECK(game2.players().size() == 3);

}
TEST_CASE("Captain")
{
    Game game2;
    Captain captain1{game2, "VS code vs Clion"};
    Captain captain2{game2, "common files x86"};
    captain1.block(captain2);
    CHECK_THROWS(captain2.steal(captain1));
    captain1.foreign_aid();
    CHECK_NOTHROW(captain2.steal(captain1));
    CHECK(captain1.coins() == 2);
    Captain captain3{game2, "GForce 1050 Ti"};
    CHECK_NOTHROW(captain3.steal(captain1));
    CHECK(captain3.coins() == 2);
}
TEST_CASE("Game")
{

}
TEST_CASE("role")
{

}


