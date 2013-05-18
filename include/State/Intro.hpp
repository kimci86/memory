#ifndef STATE_INTRO_HPP
#define STATE_INTRO_HPP

#include "State/State.hpp"

namespace State
{

class Intro : public State
{
    public:
        Intro(Game& game);
        ~Intro();

        virtual void handle(Game& game, const sf::Event& event);
        virtual void update(Game& game, sf::Time frameTime);
        virtual void draw(Game& game) const;

    private:
        sf::Text m_text;
};

} // namespace State

#endif // STATE_INTRO_HPP
