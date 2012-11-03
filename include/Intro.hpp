#ifndef INTRO_HPP
#define INTRO_HPP

#include "State.hpp"

class Intro : public State
{
    public:
        virtual State* run(Game& game);
};

#endif // INTRO_HPP
