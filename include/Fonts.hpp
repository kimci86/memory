#ifndef FONTS_HPP
#define FONTS_HPP

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class Fonts : private std::map<std::string, sf::Font>
{
    public:
        ~Fonts();

        bool hasFont(const std::string& name);
        sf::Font& getFont(const std::string& name);

        void addFont(const std::string& name, const sf::Font& font);
        bool loadFont(const std::string& name, const std::string& filename = std::string());

        sf::Text getText(const std::string& name, const std::string& string, const sf::Color& color = sf::Color::Black, unsigned int size = 30);
        static sf::Text getText(const std::string& string, const sf::Color& color = sf::Color::Black, unsigned int size = 30);
};

#endif // FONTS_HPP
