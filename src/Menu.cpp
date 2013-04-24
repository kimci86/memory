#include "Menu.hpp"
#include "Log.hpp"

Menu::Menu(Game& game)
{
    log() << "Menu" << std::endl;
    m_text = game.res.getText("DejaVu.ttf", "Menu\nEsc. pour quitter", sf::Color::White);
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

void Menu::update(Game& game, sf::Time elapsedTime)
{}

void Menu::draw(Game& game)
{
    game.window.draw(m_text);
}
