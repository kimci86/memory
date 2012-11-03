#include "Fonts.hpp"
#include "Console.hpp"

Fonts::~Fonts()
{
    for(iterator ite = begin(); ite != end(); ++ite)
        log() << "Removed " << ite->first << std::endl;
}

bool Fonts::hasFont(const std::string& name)
{
    return find(name) != end();
}

sf::Font& Fonts::getFont(const std::string& name)
{
    return (*this)[name];
}

void Fonts::addFont(const std::string& name, const sf::Font& font)
{
    log() << (hasFont(name) ? "Replaced " : "Added ") << name << std::endl;
    getFont(name) = font;
}

bool Fonts::loadFont(const std::string& name, const std::string& filename)
{
    sf::Font font;
    if(!font.loadFromFile(std::string("data/fonts/") + (filename != std::string() ? filename : name)))
    {
        err() << "Can not load " << name << std::endl;
        return false;
    }
    else
    {
        addFont(name, font);
        return true;
    }
}

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

