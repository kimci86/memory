#include "State/Intro.hpp"
#include "Log.hpp"
#include "State/Menu.hpp"

namespace State
{

Intro::Intro(Game& game)
{
    log() << "Intro" << std::endl;
    m_text = game.res.getText("DejaVu.ttf", "Intro", sf::Color::White, 150);
}

Intro::~Intro()
{
    log() << "~Intro" << std::endl;
}

void Intro::handle(Game& game, const sf::Event& event)
{
    if(event.type == sf::Event::Closed)
        game.stop();
}

void Intro::update(Game& game, sf::Time elapsedTime)
{
    m_elapsedTime += elapsedTime;
    if(m_elapsedTime >= sf::seconds(1.f))
        game.setState(new Future<Menu>);
}

void Intro::draw(Game& game)
{
    game.window.draw(m_text);
}

} // namespace State
