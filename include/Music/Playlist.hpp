#ifndef MUSIC_PLAYLIST_HPP
#define MUSIC_PLAYLIST_HPP

#include <string>
#include <vector>

namespace Music
{

class Playlist
{
    public:
        bool load(const std::string& filename);

        void add(const std::string& filename);
        void remove(int index);
        void clear();

        int getSize() const;

        std::string operator[](int index) const;

    private:
        std::vector<std::string> m_filenames;
};

} // namespace Music

#endif // MUSIC_PLAYLIST_HPP
