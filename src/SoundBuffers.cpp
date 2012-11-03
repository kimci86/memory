#include "SoundBuffers.hpp"

sf::Sound SoundBuffers::getSound(const std::string& name)
{
    if(!hasSoundBuffer(name))
        loadSoundBuffer(name);

    return sf::Sound(getSoundBuffer(name));
}
