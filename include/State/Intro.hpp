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
        virtual void update(Game& game, sf::Time elapsedTime);
        virtual void draw(Game& game);

    private:
        sf::Time m_elapsedTime;
        sf::Text m_text;
};

} // namespace State

#endif // STATE_INTRO_HPP
