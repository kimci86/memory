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
        virtual void update(Game& game, sf::Time frameTime);
        virtual void draw(Game& game) const;

    private:
        sf::Text m_text;
        std::vector<sf::Text> m_items;
};

} // namespace State

#endif // STATE_MENU_HPP
