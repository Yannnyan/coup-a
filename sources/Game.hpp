#include <string>
#include <vector>



namespace coup
{
    class Game
    {
        private:
            // list of names of the playing characters
            std::vector<std::string> players;
            // the name of the current player's turn
            std::string player_turn;
        public:
            // constructors
            Game();
            // geters and settern
            std::string set_turn(std::string player);
            //returns the name of the player to play next
            std::string turn();
            // returns who is the winner of the game.
            // if the game is still in progress, then throw exception.
            std::string winner();
            // returns a vector of strings which contains the names of the players in the game
            std::vector<std::string> players();
    };
}





