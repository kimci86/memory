#include "Textures.hpp"

Textures::Textures()
 : ResourceManager<sf::Texture>("graphics")
{}

sf::Sprite Textures::getSprite(const std::string& name, const sf::IntRect& rect)
{
    if(!has(name))
        load(name);

    if(rect == sf::IntRect())
        return sf::Sprite(get(name));
    else
        return sf::Sprite(get(name), rect);
}
