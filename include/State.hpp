#ifndef STATE_HPP
#define STATE_HPP

#include "Game.hpp"

class State
{
    public:
        virtual ~State() {}

        virtual void handle(Game& game, const sf::Event& event) = 0;
        virtual void update(Game& game, sf::Time elapsedTime) = 0;
        virtual void draw(Game& game) = 0;
};

class FutureState
{
    public:
        virtual State* createState(Game& game) const = 0;
};

template <typename T>
class Future : public FutureState
{
    public:
        virtual State* createState(Game& game) const
        {
            return new T(game);
        }
};

#endif // STATE_HPP
