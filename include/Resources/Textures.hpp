#ifndef RESOURCES_TEXTURES_HPP
#define RESOURCES_TEXTURES_HPP

#include <SFML/Graphics.hpp>
#include "Resources/ResourceManager.hpp"

namespace Resources
{

class Textures : public ResourceManager<sf::Texture>
{
    public:
        Textures();

        sf::Sprite getSprite(const std::string& name, const sf::IntRect& rect = sf::IntRect());
};

} // namespace Resources

#endif // RESOURCES_TEXTURES_HPP
