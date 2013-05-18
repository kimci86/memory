#include <cmath>
#include "State/Menu.hpp"
#include "Log.hpp"

namespace State
{

Menu::Menu(Game& game)
{
    log() << "Menu" << std::endl;
    m_text = game.res.getText("DejaVu.ttf", "Memory", sf::Color::White);
    m_text.setPosition((int) (game.settings.mode.width - m_text.getLocalBounds().width)/2, 60);
    
    std::string strs[] = {"Play", "Settings", "Leave"};
    for (int i=0; i<3; ++i) {
        sf::Text item = game.res.getText("DejaVu.ttf", strs[i], sf::Color::White);
        sf::FloatRect r = item.getLocalBounds();
        item.setOrigin(r.width/2.f, r.height/2.f);
        item.setPosition(game.settings.mode.width/2, 180 + 60*i);
        m_items.push_back(item);
    }
}

Menu::~Menu()
{
    log() << "~Menu" << std::endl;
}

void Menu::handle(Game& game, const sf::Event& event)
{
    if(event.type == sf::Event::Closed)
        game.stop();
    else if(event.type == sf::Event::KeyReleased)
        if(event.key.code == sf::Keyboard::Escape)
            game.stop();
}

void Menu::update(Game& game, sf::Time frameTime)
{
    State::update(game, frameTime);
    
    const int duration = 600;
    const int offset = 200;
    const int totalDuration = duration + m_items.size()*200;
    
    if (getElapsedTime().asMilliseconds() <= totalDuration)
    {
        int totalOffset = 0;
        for (std::vector<sf::Text>::iterator it = m_items.begin(); it != m_items.end(); ++it)
        {
            int t = getElapsedTime().asMilliseconds() - totalOffset;
            it->setScale((t < 0)? 0 : ((t > duration)? 1.f : std::sin(t * (M_PI/2) / duration)), 1.f);
            totalOffset += offset;
        }
    }
}

void Menu::draw(Game& game) const
{
    game.window.draw(m_text);
    
    for (std::vector<sf::Text>::const_iterator it = m_items.begin(); it != m_items.end(); ++it) {
        game.window.draw(*it);
    }
}

} // namespace State
