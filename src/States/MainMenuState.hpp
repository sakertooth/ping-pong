#pragma once
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "../GameObjects/Button.hpp"
#include "../GameObjects/Ball.hpp"
#include "../GameObjects/Paddle.hpp"

class MainMenuState : public State {
public:
    virtual void init() override;
    virtual void update(const sf::Time& deltaTime) override;

private:
    Button onePlayerButton;
    Button twoPlayerButton;
    Button exitButton;
    
    sf::Text title;
    sf::Music music;

    Paddle backgroundPaddleLeft;
    Paddle backgroundPaddleRight;
    Ball backgroundBall;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};