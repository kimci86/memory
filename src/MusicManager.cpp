#include "MusicManager.hpp"
#include "Log.hpp"

bool MusicManager::setMusic(const std::string& filename)
{
    if(filename == "")
    {
        music.stop();
        return true;
    }
    else if(!music.openFromFile(std::string("data/musics/") + filename))
    {
        warn() << "Can't open " << filename << std::endl;
        return false;
    }
    else
    {
        log() << "Opened music " << filename << std::endl;
        music.play();
        return true;
    }
}

