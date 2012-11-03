#ifndef FONTS_HPP
#define FONTS_HPP

#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class Fonts : public ResourceManager<sf::Font, "fonts">
{
    public:
        sf::Text getText(const std::string& name, const std::string& string, const sf::Color& color = sf::Color::Black, unsigned int size = 30);
        static sf::Text getText(const std::string& string, const sf::Color& color = sf::Color::Black, unsigned int size = 30);
};

#endif // FONTS_HPP
