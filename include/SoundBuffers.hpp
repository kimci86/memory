#ifndef SOUNDBUFFERS_HPP
#define SOUNDBUFFERS_HPP

#include <SFML/Audio.hpp>
#include "ResourceManager.hpp"

class SoundBuffers : public ResourceManager<sf::SoundBuffer>
{
    public:
        SoundBuffers();

        sf::Sound getSound(const std::string& name);
};

#endif // SOUNDBUFFERS_HPP
