#include "Music/Player.hpp"
#include "Log.hpp"

namespace Music
{

Player::Player()
 : m_thread(&Player::run, this), m_running(false)
{}

Player::~Player()
{
    stopThread();
}

bool Player::loadMusic(const std::string& filename)
{
    stop();
    m_playlist.clear();
    m_music.setLoop(true);
    return openMusic(filename);
}

bool Player::loadPlaylist(const std::string& filename)
{
    stop();
    m_index = 0;
    m_music.setLoop(false);
    return m_playlist.load(filename);
}

void Player::play()
{
    if(isRunning())
        return;

    if(m_playlist.getSize())
        startThread();
    else
        m_music.play();
}

void Player::pause()
{
    sf::Lock lock(m_mutex);
    m_music.pause();
}

void Player::stop()
{
    stopThread();
    m_music.stop();
}

bool Player::openMusic(const std::string& filename)
{
    if(!m_music.openFromFile(std::string("data/musics/") + filename))
    {
        warn() << "Can't open " << filename << std::endl;
        return false;
    }
    else
    {
        log() << "Opened music " << filename << std::endl;
        return true;
    }
}

void Player::startThread()
{
    if(!isRunning())
    {
        m_running = true;
        m_thread.launch();
    }
}

void Player::stopThread()
{
    if(isRunning())
    {
        {
            sf::Lock lock(m_mutex);
            m_running = false;
        }
        m_thread.wait();
    }
}

bool Player::isRunning()
{
    sf::Lock lock(m_mutex);
    return m_running;
}

void Player::run()
{
    while(isRunning())
    {
        // Thread safe block
        {
            sf::Lock lock(m_mutex);
            if(m_music.getStatus() == sf::Music::Stopped)
            {
                while(!openMusic(m_playlist[m_index]))
                {
                    m_playlist.remove(m_index);
                    if(!m_playlist.getSize())
                    {
                        m_running = false;
                        return;
                    }
                    m_index %= m_playlist.getSize();
                }

                m_music.play();

                m_index++;
                m_index %= m_playlist.getSize();
            }
        }
        sf::sleep(sf::milliseconds(200));
    }
}

} // namespace Music
