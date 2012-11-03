#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Settings.hpp"
#include "Resources.hpp"
#include "MusicManager.hpp"

class Game
{
    public:
        Game();

        bool run();

        bool error; // Did an error occur ?
        sf::RenderWindow window;
        Settings settings;
        Resources res; // global resources
        MusicManager music;
};

#endif // GAME_HPP
