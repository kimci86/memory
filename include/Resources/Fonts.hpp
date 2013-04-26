#ifndef RESOURCES_FONTS_HPP
#define RESOURCES_FONTS_HPP

#include <SFML/Graphics.hpp>
#include "Resources/ResourceManager.hpp"

namespace Resources
{

class Fonts : public ResourceManager<sf::Font>
{
    public:
        Fonts();

        sf::Text getText(const std::string& name, const std::string& string, const sf::Color& color = sf::Color::Black, unsigned int size = 30);
};

} // namespace Resources

#endif // RESOURCES_FONTS_HPP
