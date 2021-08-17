#include "Paddle.hpp"
#include <iostream>

Paddle::Paddle() {}

Paddle::Paddle(const sf::Vector2f& position, const sf::Vector2f& size, PaddleOrientation orientation, Ball* activeBall) {
    rect.setSize(size);
    rect.setPosition(position);
    rect.setFillColor(sf::Color::White);
    rect.setOrigin(rect.getLocalBounds().width / 2.0f, rect.getLocalBounds().height / 2.0f);

    this->speed = 500;
    this->activeBall = activeBall;
    this->orientation = orientation;
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
}

void Paddle::update(const sf::Time& deltaTime) {
    const auto ballBounds = activeBall->getCircle().getGlobalBounds();
    const auto paddleBounds = rect.getGlobalBounds();

    auto intersections = getIntersectionRects();
    auto ballIntersectionRect = std::get<0>(intersections);
    auto paddleIntersectionRect = std::get<1>(intersections);

    float offsetX = 0;
    float offsetY = 0;
    
    switch(orientation) {
        case PaddleOrientation::LEFT:
            offsetX = 1.0f;
            break;
        case PaddleOrientation::RIGHT:
            offsetX = -1.0f;
            break;
        case PaddleOrientation::DOWN:
            offsetY = -1.0f;
            break;
    }

    const auto ballAngle = activeBall->getAngle();
    const auto ballPos = activeBall->getCircle().getPosition();
    if (paddleIntersectionRect.intersects(ballIntersectionRect)) {
        activeBall->getCircle().setPosition(ballPos.x + offsetX, ballPos.y + offsetY);

        switch(orientation) {
            case Paddle::PaddleOrientation::LEFT:
            case Paddle::PaddleOrientation::RIGHT:
                activeBall->reflect(Ball::Axis::Y);
                break;
            case Paddle::PaddleOrientation::DOWN:
                activeBall->reflect(Ball::Axis::X);
        }
    }
}

int Paddle::getSpeed() {
    return speed;
}

sf::RectangleShape& Paddle::getRect() {
    return rect;
}

Paddle::PaddleOrientation Paddle::getOrientation() {
    return orientation;
}

std::pair<sf::FloatRect, sf::FloatRect> Paddle::getIntersectionRects() {
    const auto ballBounds = activeBall->getCircle().getGlobalBounds();
    const auto paddleBounds = rect.getGlobalBounds();

    sf::FloatRect ballIntersectionRect;
    sf::FloatRect paddleIntersectionRect;

    switch(orientation) {
        case PaddleOrientation::LEFT:
            ballIntersectionRect.left = ballBounds.left;
            ballIntersectionRect.top = ballBounds.top;
            ballIntersectionRect.height = ballBounds.height;
            ballIntersectionRect.width = 1;

            paddleIntersectionRect.left = paddleBounds.left + paddleBounds.width;
            paddleIntersectionRect.top = paddleBounds.top;
            paddleIntersectionRect.height = paddleBounds.height;
            paddleIntersectionRect.width = 1;
            break;
        case PaddleOrientation::RIGHT:
            ballIntersectionRect.left = ballBounds.left + ballBounds.width;
            ballIntersectionRect.top = ballBounds.top;
            ballIntersectionRect.width = 1;
            ballIntersectionRect.height = ballBounds.height;
            
            paddleIntersectionRect.left = paddleBounds.left; 
            paddleIntersectionRect.top = paddleBounds.top;
            paddleIntersectionRect.width = 1;
            paddleIntersectionRect.height = paddleBounds.height;
            break;
        case PaddleOrientation::DOWN:
            ballIntersectionRect.left = ballBounds.left;
            ballIntersectionRect.top = ballBounds.top + ballBounds.height;
            ballIntersectionRect.width = ballBounds.width;
            ballIntersectionRect.height = 1;

            paddleIntersectionRect.left = paddleBounds.left;
            paddleIntersectionRect.top = paddleBounds.top;
            paddleIntersectionRect.width = paddleBounds.width;
            paddleIntersectionRect.height = 1;
            break;
    }

    return std::make_pair(ballIntersectionRect, paddleIntersectionRect);
}

void Paddle::moveUp(const sf::Time& deltaTime) {
    rect.move(0, -speed * deltaTime.asSeconds());
}

void Paddle::moveDown(const sf::Time& deltaTime) {
    rect.move(0, speed * deltaTime.asSeconds());
}

void Paddle::moveLeft(const sf::Time& deltaTime) {
    rect.move(-speed * deltaTime.asSeconds(), 0);
}

void Paddle::moveRight(const sf::Time& deltaTime) {
    rect.move(speed * deltaTime.asSeconds(), 0);
}