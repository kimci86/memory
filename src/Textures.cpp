#include "Textures.hpp"

sf::Sprite Textures::getSprite(const std::string& name, const sf::IntRect& rect)
{
    if(!hasTexture(name))
        loadTexture(name);

    if(rect == sf::IntRect())
        return sf::Sprite(getTexture(name));
    else
        return sf::Sprite(getTexture(name), rect);
}
