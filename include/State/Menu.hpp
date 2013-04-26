#ifndef STATE_MENU_HPP
#define STATE_MENU_HPP

#include "State/State.hpp"

namespace State
{

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

} // namespace State

#endif // STATE_MENU_HPP
