#pragma once
#include "../Updatable.hpp"
#include "../GameObjects/Paddle.hpp"
#include "../GameObjects/Ball.hpp"

class OnePlayerState : public Updatable {
public:
    OnePlayerState();
    void update(const sf::Time& deltaTime) override;
private:
    Paddle paddle;
    Ball ball;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};