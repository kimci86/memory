#include "Game.hpp"
#include "Intro.hpp"

Game::Game()
 : m_isRunning(false), m_error(false), m_futureState(0)
{
    settings.load();
    window.create(settings.mode, "Game");
    window.setFramerateLimit(50);
    res.Fonts::load("DejaVu.ttf");
}

Game::~Game()
{
    window.close();
    settings.save();
}

void Game::setState(FutureState* futureState)
{
    delete m_futureState;
    m_futureState = futureState;
}

bool Game::run()
{
    State* state = new Intro(*this);
    m_isRunning = true;
    m_clock.restart();

    while(m_isRunning)
    {
        sf::Event event;
        while(window.pollEvent(event))
            state->handle(*this, event);

        state->update(*this, m_clock.restart());

        window.clear();
        state->draw(*this);
        window.display();

        if(m_futureState)
        {
            delete state;
            state = m_futureState->createState(*this);
            delete m_futureState;
            m_futureState = 0;
        }
    }

    delete state;

    return !m_error;
}

void Game::stop(bool error)
{
    m_isRunning = false;
    m_error = error;
}
