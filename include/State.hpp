#ifndef STATE_HPP
#define STATE_HPP

#include "Game.hpp"

class State
{
    public:
        virtual ~State() {}

        virtual State* run(Game& game) = 0;
};

#endif // STATE_HPP
