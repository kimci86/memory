#ifndef INTRO_HPP
#define INTRO_HPP

#include "State.hpp"

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

#endif // INTRO_HPP
