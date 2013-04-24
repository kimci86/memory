#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Settings.hpp"
#include "Resources.hpp"
#include "MusicManager.hpp"

class FutureState;

class Game
{
    public:
        Game();
        ~Game();

        void setState(FutureState* futureState);

        bool run();

        void stop(bool error = false);

        sf::RenderWindow window;
        Settings settings;
        Resources res; // global resources
        MusicManager music;

    private:
        bool m_isRunning;
        bool m_error;
        sf::Clock m_clock;
        FutureState* m_futureState;
};

#endif // GAME_HPP
