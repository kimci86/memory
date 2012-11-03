#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "Textures.hpp"
#include "Fonts.hpp"
#include "SoundBuffers.hpp"

#include <iostream>

class Resources : public Textures, public Fonts, public SoundBuffers
{

};

#endif // RESOURCES_HPP
