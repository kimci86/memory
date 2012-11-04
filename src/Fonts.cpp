#include "Fonts.hpp"

Fonts::Fonts()
 : ResourceManager<sf::Font>("fonts")
{}

sf::Text Fonts::getText(const std::string& name, const std::string& string, const sf::Color& color, unsigned int size)
{
    if(!has(name))
        load(name);

    sf::Text text(string, get(name), size);
    text.setColor(color);
    return text;
}
