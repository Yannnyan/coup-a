



enum roles{Assassin, Ambassador, Duke, Contessa, Captain};
namespace coup
{
    class role
    {
        private:
            enum roles player_role;

        public:
            // this function receives a role and sets the player's role
            void setRole(enum roles role);
            // returns the role of the player
            void getRole();
    };
}