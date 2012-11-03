#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/Graphics.hpp>

class Settings
{
    public:
        bool load();
        bool save();

        sf::VideoMode mode;
};

#endif // SETTINGS_HPP
