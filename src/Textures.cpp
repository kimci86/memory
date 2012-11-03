#include "Textures.hpp"
#include "Console.hpp"

Textures::~Textures()
{
    for(iterator ite = begin(); ite != end(); ++ite)
        log() << "Removed " << ite->first << std::endl;
}

bool Textures::hasTexture(const std::string& name)
{
    return find(name) != end();
}

sf::Texture& Textures::getTexture(const std::string& name)
{
    return (*this)[name];
}

void Textures::addTexture(const std::string& name, const sf::Texture& texture)
{
    log() << (hasTexture(name) ? "Replaced " : "Added ") << name << std::endl;
    getTexture(name) = texture;
}

bool Textures::loadTexture(const std::string& name, const std::string& filename)
{
    sf::Texture texture;
    if(!texture.loadFromFile(std::string("data/graphics/") + (filename != std::string() ? filename : name)))
    {
        err() << "Can not load " << name << std::endl;
        return false;
    }
    else
    {
        addTexture(name, texture);
        return true;
    }
}

sf::Sprite Textures::getSprite(const std::string& name, const sf::IntRect& rect)
{
    if(!hasTexture(name))
        loadTexture(name);

    if(rect == sf::IntRect())
        return sf::Sprite(getTexture(name));
    else
        return sf::Sprite(getTexture(name), rect);
}
