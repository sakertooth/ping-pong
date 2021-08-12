#pragma once
#include "State.hpp"
#include "../GameObjects/Button.hpp"

class MainMenuState : public State {
public:
    virtual void update(const sf::Time& deltaTime) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    Button twoPlayerButton;
};