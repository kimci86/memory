#ifndef MUSICMANAGER_HPP
#define MUSICMANAGER_HPP

#include <string>
#include <SFML/Audio.hpp>

class MusicManager
{
    public:
        bool setMusic(const std::string& filename);

        sf::Music music;
};

#endif // MUSICMANAGER_HPP
