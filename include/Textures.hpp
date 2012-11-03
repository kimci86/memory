#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class Textures : private std::map<std::string, sf::Texture>
{
    public:
        ~Textures();

        bool hasTexture(const std::string& name);
        sf::Texture& getTexture(const std::string& name);

        void addTexture(const std::string& name, const sf::Texture& texture);
        bool loadTexture(const std::string& name, const std::string& filename = std::string());

        sf::Sprite getSprite(const std::string& name, const sf::IntRect& rect = sf::IntRect());
};

#endif // TEXTURES_HPP
