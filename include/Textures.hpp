#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class Textures : public ResourceManager<sf::Texture>
{
    public:
        Textures();

        sf::Sprite getSprite(const std::string& name, const sf::IntRect& rect = sf::IntRect());
};

#endif // TEXTURES_HPP
