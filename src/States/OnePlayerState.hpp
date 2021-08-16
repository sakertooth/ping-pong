#pragma once
#include "State.hpp"
#include "../GameObjects/Paddle.hpp"
#include "../GameObjects/Ball.hpp"

class OnePlayerState : public State {
public:
    void update(const sf::Time& deltaTime) override;
    void init() override;
private:
    Paddle paddle;
    Ball ball;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};