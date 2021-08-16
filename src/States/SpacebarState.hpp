#pragma once
#include "State.hpp"
#include "../Game.hpp"
#include <memory>

class SpacebarState : public State {
public:
    SpacebarState(std::shared_ptr<State> nextState);
    virtual void init() override;
    virtual void update(const sf::Time& deltaTime) override;
private:
    std::shared_ptr<State> nextState;
    sf::Text spacebarContinueText;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};