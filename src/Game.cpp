#include "Game.hpp"
#include "Intro.hpp"
#include <iostream>

Game::Game()
 : error(false)
{
    settings.load();
    window.create(settings.mode, "Game");
    window.setFramerateLimit(50);
}

bool Game::run()
{
    State* state = new Intro;
    while(state)
    {
        State* next = state->run(*this);
        delete state;
        state = next;
        if(error)
        {
            delete state;
            return false;
        }
    }
    return true;
}
