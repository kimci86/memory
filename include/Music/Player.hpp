#ifndef MUSIC_PLAYER_HPP
#define MUSIC_PLAYER_HPP

#include <string>
#include <SFML/Audio.hpp>
#include "Music/Playlist.hpp"

namespace Music
{

class Player
{
    public:
        Player();
        ~Player();

        bool loadMusic(const std::string& filename);
        bool loadPlaylist(const std::string& filename);

        void play();
        void pause();
        void stop();

    private:
        sf::Music m_music;
        bool openMusic(const std::string& filename);

        Playlist m_playlist;
        int m_index;

        sf::Thread m_thread;
        sf::Mutex m_mutex;
        bool m_running;

        void startThread();
        void stopThread();
        bool isRunning();

        void run();
};

} // namespace Music

#endif // MUSIC_PLAYER_HPP
