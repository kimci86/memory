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
        item.setPosition((int) (game.settings.mode.width - r.width)/2, 180 + 60*i);
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
    
    
}

void Menu::draw(Game& game) const
{
    game.window.draw(m_text);
    
    for (std::vector<sf::Text>::const_iterator it = m_items.begin(); it != m_items.end(); ++it) {
        game.window.draw(*it);
    }
}

} // namespace State
