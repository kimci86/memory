#include "Settings.hpp"
#include "Log.hpp"

bool Settings::load()
{
    // default resolution
    mode = sf::VideoMode(800, 600);
    log() << "\"Loaded\" settings" << std::endl;
    return true;
}

bool Settings::save()
{
    log() << "\"Saved\" settings" << std::endl;
    return true;
}
