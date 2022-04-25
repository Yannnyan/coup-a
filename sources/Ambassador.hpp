#include "Player.hpp"



namespace coup
{
    class Ambassador
    {
        private:
        public:
            // transfers one coin from source to dest
            void transfer(Player source, Player dest);
            // function name is not current waiting to change it
            // this function supposed to block the Captain from stealing coins from other players.
            void avoid_steal(Player source);
    };

}



