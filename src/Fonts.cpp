#include "Fonts.hpp"

sf::Text Fonts::getText(const std::string& name, const std::string& string, const sf::Color& color, unsigned int size)
{
    if(!hasFont(name))
        loadFont(name);

    sf::Text text(string, getFont(name), size);
    text.setColor(color);
    return text;
}

sf::Text Fonts::getText(const std::string& string, const sf::Color& color, unsigned int size)
{
    sf::Text text(string, sf::Font::getDefaultFont(), size);
    text.setColor(color);
    return text;
}

