#ifndef RESOURCES_SOUNDBUFFERS_HPP
#define RESOURCES_SOUNDBUFFERS_HPP

#include <SFML/Audio.hpp>
#include "Resources/ResourceManager.hpp"

namespace Resources
{

class SoundBuffers : public ResourceManager<sf::SoundBuffer>
{
    public:
        SoundBuffers();

        sf::Sound getSound(const std::string& name);
};

} // namespace Resources

#endif // RESOURCES_SOUNDBUFFERS_HPP
