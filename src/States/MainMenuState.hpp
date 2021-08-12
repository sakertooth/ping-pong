#pragma once
#include "State.hpp"
#include "../GameObjects/Button.hpp"

class MainMenuState : public State {
public:
    virtual void update(const sf::Time& deltaTime) override;
    virtual void init() override;

private:
    Button onePlayerButton;
    Button twoPlayerButton;
    Button exitButton;
    sf::Text title;

   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};