#include "Paddle.hpp"
#include <iostream>
#include <cmath>

Paddle::Paddle() {}

Paddle::Paddle(const sf::Vector2f& position, PaddleOrientation orientation) {
    rect.setSize((orientation == PaddleOrientation::LEFT || orientation == PaddleOrientation::RIGHT) ? 
                    sf::Vector2f{5, 75} : sf::Vector2f{75, 5});
    rect.setPosition(position);
    rect.setFillColor(sf::Color::White);
    rect.setOrigin(rect.getLocalBounds().width / 2.0f, rect.getLocalBounds().height / 2.0f);

    this->speed = 500;
    this->orientation = orientation;
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
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