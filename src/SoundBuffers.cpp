#include "SoundBuffers.hpp"

SoundBuffers::SoundBuffers()
 : ResourceManager<sf::SoundBuffer>("sounds")
{}

sf::Sound SoundBuffers::getSound(const std::string& name)
{
    if(!has(name))
        load(name);

    return sf::Sound(get(name));
}
