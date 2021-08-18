#include "Paddle.hpp"
#include <iostream>
#include <cmath>

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
    auto ballBounds = activeBall->getGlobalBounds();
    auto paddleBounds = rect.getGlobalBounds();
    auto ballRadius = activeBall->getRadius();

    auto intersections = getIntersectionRects();
    auto ballIntersectionRect = std::get<0>(intersections);
    auto paddleIntersectionRect = std::get<1>(intersections);

    float offsetX = 0;
    float offsetY = 0;
    
    switch(orientation) {
        case PaddleOrientation::LEFT:
            offsetX = ballRadius;
            break;
        case PaddleOrientation::RIGHT:
            offsetX = -ballRadius;
            break;
        case PaddleOrientation::DOWN:
            offsetY = -ballRadius;
            break;
    }

    auto ballPos = activeBall->getPosition();    
    if (paddleIntersectionRect.intersects(ballIntersectionRect)) {
        activeBall->setPosition(ballPos.x + offsetX, ballPos.y + offsetY);
        const auto distance = (orientation == PaddleOrientation::LEFT || orientation == PaddleOrientation::RIGHT) 
                                ? ballPos.y - rect.getPosition().y : ballPos.x - rect.getPosition().x;

        auto increaseSpeed = [&]() {
            auto ballSpeed = activeBall->getSpeed();
            if (ballSpeed < activeBall->getMaxSpeed()) {
                activeBall->setSpeed(ballSpeed + activeBall->getAcceleration());
            }
        };

        switch (orientation) {
            case PaddleOrientation::LEFT:
            case PaddleOrientation::RIGHT:
                activeBall->reflect(Ball::VectorComponent::X);
                if ((distance > 0 && distance < 15 && std::sin(activeBall->getAngle()) < 0) || 
                    (distance > paddleBounds.height - 15 && distance < paddleBounds.height) && std::sin(activeBall->getAngle()) > 0) {       
                    activeBall->reflect(Ball::VectorComponent::Y);
                    increaseSpeed();
                }
                break;
            case PaddleOrientation::DOWN:
                activeBall->reflect(Ball::VectorComponent::Y);
                if ((distance > 0 && distance < 15 && std::cos(activeBall->getAngle()) < 0) || 
                    (distance > paddleBounds.width - 15 && distance < paddleBounds.width) && std::cos(activeBall->getAngle()) > 0) {       
                    activeBall->reflect(Ball::VectorComponent::X);
                    increaseSpeed();
                }
                break;
        }
    }
}

int Paddle::getSpeed() const {
    return speed;
}

Paddle::PaddleOrientation Paddle::getOrientation() const {
    return orientation;
}

const sf::Vector2f& Paddle::getPosition() const {
    return rect.getPosition();
}

sf::FloatRect Paddle::getGlobalBounds() const {
    return rect.getGlobalBounds();
}

sf::FloatRect Paddle::getLocalBounds() const {
    return rect.getLocalBounds();
}

std::pair<sf::FloatRect, sf::FloatRect> Paddle::getIntersectionRects() const {
    const auto ballBounds = activeBall->getGlobalBounds();
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