#ifndef RESOURCES_RESOURCES_HPP
#define RESOURCES_RESOURCES_HPP

#include "Resources/Textures.hpp"
#include "Resources/Fonts.hpp"
#include "Resources/SoundBuffers.hpp"

namespace Resources
{

class Resources : public Textures, public Fonts, public SoundBuffers
{

};

} // namespace Resources

#endif // RESOURCES_RESOURCES_HPP
