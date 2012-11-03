#include "SoundBuffers.hpp"
#include "Console.hpp"

SoundBuffers::~SoundBuffers()
{
    for(iterator ite = begin(); ite != end(); ++ite)
        log() << "Removed " << ite->first << std::endl;
}

bool SoundBuffers::hasSoundBuffer(const std::string& name)
{
    return find(name) != end();
}

sf::SoundBuffer& SoundBuffers::getSoundBuffer(const std::string& name)
{
    return (*this)[name];
}

void SoundBuffers::addSoundBuffer(const std::string& name, const sf::SoundBuffer& soundBuffer)
{
    log() << (hasSoundBuffer(name) ? "Replaced " : "Added ") << name << std::endl;
    getSoundBuffer(name) = soundBuffer;
}

bool SoundBuffers::loadSoundBuffer(const std::string& name, const std::string& filename)
{
    sf::SoundBuffer soundBuffer;
    if(!soundBuffer.loadFromFile(std::string("data/sounds/") + (filename != std::string() ? filename : name)))
    {
        err() << "Can not load " << name << std::endl;
        return false;
    }
    else
    {
        addSoundBuffer(name, soundBuffer);
        return true;
    }
}

sf::Sound SoundBuffers::getSound(const std::string& name)
{
    if(!hasSoundBuffer(name))
        loadSoundBuffer(name);

    return sf::Sound(getSoundBuffer(name));
}
