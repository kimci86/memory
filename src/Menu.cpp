#include "Menu.hpp"
#include "Log.hpp"

State* Menu::run(Game& game)
{
    log() << "Menu" << std::endl;

    sf::Text text = game.res.getText("DejaVu.ttf", "Menu\nEsc. pour quitter", sf::Color::White);

    while(game.window.isOpen())
    {
        sf::Event event;
        while(game.window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                game.window.close();
            else if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Escape)
                    game.window.close();
            }
        }

        game.window.clear();
        game.window.draw(text);
        game.window.display();
    }

    return 0;
}