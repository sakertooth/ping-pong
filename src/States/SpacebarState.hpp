#pragma once
#include "../Updatable.hpp"
#include <memory>

class SpacebarState : public Updatable {
public:
    SpacebarState(std::unique_ptr<Updatable> nextState);
    virtual void update(const sf::Time& deltaTime) override;
private:
    std::unique_ptr<Updatable> nextState;
    sf::Text spacebarContinueText;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};