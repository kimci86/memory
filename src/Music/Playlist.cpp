#include "Music/Playlist.hpp"
#include "Log.hpp"
#include <fstream>

namespace Music
{

bool Playlist::load(const std::string& filename)
{
    clear();
    std::ifstream ifs((std::string("data/musics/") + filename).c_str());
    if(!ifs)
    {
        warn() << "Can't open " << filename << std::endl;
        return false;
    }
    else
    {
        std::string line;
        while(std::getline(ifs, line))
            if(line != "" && line[0] != '#')
                add(line);
        log() << "Loaded playlist " << filename << std::endl;
        return true;
    }
}

void Playlist::add(const std::string& filename)
{
    m_filenames.push_back(filename);
}

void Playlist::remove(int index)
{
    m_filenames.erase(m_filenames.begin() + index);
}

void Playlist::clear()
{
    m_filenames.clear();
}

int Playlist::getSize() const
{
    return m_filenames.size();
}

std::string Playlist::operator[](int index) const
{
    return m_filenames[index];
}

} // namespace Music
