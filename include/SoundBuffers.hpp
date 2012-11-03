#ifndef SOUNDBUFFERS_HPP
#define SOUNDBUFFERS_HPP

#include <map>
#include <string>
#include <SFML/Audio.hpp>

class SoundBuffers : private std::map<std::string, sf::SoundBuffer>
{
    public:
        ~SoundBuffers();

        bool hasSoundBuffer(const std::string& name);
        sf::SoundBuffer& getSoundBuffer(const std::string& name);

        void addSoundBuffer(const std::string& name, const sf::SoundBuffer& soundBuffer);
        bool loadSoundBuffer(const std::string& name, const std::string& filename = std::string());

        sf::Sound getSound(const std::string& name);
};

#endif // SOUNDBUFFERS_HPP
