#ifndef MENU_HPP
#define MENU_HPP

#include "State.hpp"

class Menu : public State
{
    public:
        Menu(Game& game);
        ~Menu();

        virtual void handle(Game& game, const sf::Event& event);
        virtual void update(Game& game, sf::Time elapsedTime);
        virtual void draw(Game& game);

    private:
        sf::Text m_text;
};

#endif // MENU_HPP
