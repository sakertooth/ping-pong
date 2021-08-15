#include "Paddle.hpp"
#include <iostream>

Paddle::Paddle(): speed(500), activeBall(nullptr) {
    rect.setSize({5, 75});
    rect.setOrigin(rect.getLocalBounds().width / 2.0f, rect.getLocalBounds().height / 2.0f);
    rect.setFillColor(sf::Color::White);
}

void Paddle::init(const sf::Vector2f& position, PaddleOrientation orientation, Ball* activeBall) {
    rect.setPosition(position);
    this->activeBall = activeBall;
    this->orientation = orientation;
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
}

void Paddle::update(const sf::Time& deltaTime) {
    const auto ballAngle = activeBall->getAngle();
    const auto ballSpeed = activeBall->getSpeed();
    const auto ballBounds = activeBall->getCircle().getGlobalBounds();
    const auto paddleBounds = rect.getGlobalBounds();

    sf::FloatRect ballIntersectionRect;
    ballIntersectionRect.width = 1;
    ballIntersectionRect.height = ballBounds.height;

    sf::FloatRect paddleIntersectionRect;
    paddleIntersectionRect.width = 1;
    paddleIntersectionRect.height = paddleBounds.height;

    switch(orientation) {
        case PaddleOrientation::LEFT:
            ballIntersectionRect.left = ballBounds.left;
            ballIntersectionRect.top = ballBounds.top;
            paddleIntersectionRect.left = paddleBounds.left + paddleBounds.width;
            paddleIntersectionRect.top = paddleBounds.top;
            break;
        case PaddleOrientation::RIGHT:
            ballIntersectionRect.left = ballBounds.left + ballBounds.width;
            ballIntersectionRect.top = ballBounds.top;
            paddleIntersectionRect.left = paddleBounds.left; 
            paddleIntersectionRect.top = paddleBounds.top; 
            break;
        case PaddleOrientation::DOWN:
            break;
        case PaddleOrientation::UP:
            break;
    }

    if (paddleIntersectionRect.intersects(ballIntersectionRect)) {
        activeBall->setAngle(ballAngle + 90);
    }
}

const sf::RectangleShape& Paddle::getRect() const {
    return rect;
}

void Paddle::moveUp(const sf::Time& deltaTime) {
    rect.move(0, -speed * deltaTime.asSeconds());
}

void Paddle::moveDown(const sf::Time& deltaTime) {
    rect.move(0, speed * deltaTime.asSeconds());
}