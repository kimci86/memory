#include "Intro.hpp"
#include "Log.hpp"
#include "Menu.hpp"

State* Intro::run(Game& game)
{
    log() << "Intro" << std::endl;

    sf::Text text = game.res.getText("DejaVu.ttf", "Intro", sf::Color::White, 150);
    sf::Clock clock;

    while(game.window.isOpen())
    {
        sf::Event event;
        while(game.window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                game.window.close();
                return 0;
            }
        }

        game.window.clear();
        game.window.draw(text);
        game.window.display();

        if(clock.getElapsedTime() >= sf::seconds(1.f))
            return new Menu;
    }
}
