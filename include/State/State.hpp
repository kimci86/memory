#ifndef STATE_STATE_HPP
#define STATE_STATE_HPP

#include "Game.hpp"

namespace State
{

class State
{
    public:
        virtual ~State() {}

        virtual void handle(Game& game, const sf::Event& event) = 0;
        virtual void update(Game& game, sf::Time frameTime) { m_elapsedTime += frameTime; }
        virtual void draw(Game& game) const = 0;
        const sf::Time& getElapsedTime() const { return m_elapsedTime; }
        
    protected:
        sf::Time m_elapsedTime;
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

} // namespace State

#endif // STATE_STATE_HPP
