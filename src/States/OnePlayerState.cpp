#include "OnePlayerState.hpp"
#include "../Game.hpp"
#include <cmath>
#include <iostream>

OnePlayerState::OnePlayerState() {
    const auto& window = Game::getInstance().getWindow();
    paddle = Paddle(sf::Vector2f(window.getSize().x / 2, window.getSize().y - 15.0f),
                sf::Vector2f(75, 5), 
                Paddle::PaddleOrientation::DOWN,
                &ball);

    ball.setAngle(315);
    ball.getCircle().setPosition(paddle.getRect().getPosition().x, paddle.getRect().getPosition().y - 10.0f);
}

void OnePlayerState::update(const sf::Time &deltaTime) {
    paddle.update(deltaTime);
    ball.update(deltaTime);

    const auto paddleBounds = paddle.getRect().getGlobalBounds();
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
        && paddleBounds.left > 0.0f) {

        paddle.moveLeft(deltaTime);
    }  

    const auto& window = Game::getInstance().getWindow();
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
        && paddleBounds.left + paddleBounds.width < window.getSize().x) {
        
        paddle.moveRight(deltaTime);
    }

    const auto ballPos = ball.getCircle().getPosition();
    const auto ballAngle = ball.getAngle();

    bool hitLeft = ballPos.x < 1.0f;
    bool hitRight = ballPos.x > window.getSize().x - 1.0f;

    if (hitLeft || hitRight) {
        ball.reflect(Ball::Axis::Y);
        ball.getCircle().setPosition(ball.getCircle().getPosition().x + (hitLeft ? 1.0f : -1.0f), ball.getCircle().getPosition().y);
    }
    else if (ballPos.y < 1.0f) {
        ball.reflect(Ball::Axis::X);
        ball.getCircle().setPosition(ball.getCircle().getPosition().x, ball.getCircle().getPosition().y + 1.0f);
    }
}

void OnePlayerState::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(paddle, states);
    target.draw(ball, states);
}