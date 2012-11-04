#ifndef MENU_HPP
#define MENU_HPP

#include "State.hpp"

class Menu : public State
{
    public:
        virtual State* run(Game& game);
};

#endif // MENU_HPP
