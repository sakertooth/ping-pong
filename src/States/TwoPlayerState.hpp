#pragma once
#include "../Updatable.hpp"
#include "../GameObjects/Paddle.hpp"
#include "../GameObjects/Ball.hpp"

class TwoPlayerState : public Updatable {
public:
    TwoPlayerState();
    void update(const sf::Time& deltaTime) override;

private:
    Paddle paddleLeft;
    Paddle paddleRight;
    Ball ball;

    sf::Text paddleLeftScoreText;
    int paddleLeftScore;

    sf::Text paddleRightScoreText;
    int paddleRightScore;

    sf::Text gameOverText;
    bool gameOver;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};