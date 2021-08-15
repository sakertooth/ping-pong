#include "Ball.hpp"
#include "../Game.hpp"
#include <cmath>
#include <iostream>

Ball::Ball() : speed(500), angle(45) {
    circle.setRadius(5);
    circle.setPosition(5, 5);
    circle.setOrigin(circle.getLocalBounds().width / 2.0f, circle.getLocalBounds().height / 2.0f);
    circle.setFillColor(sf::Color::White);
}

void Ball::update(const sf::Time& deltaTime) {
    const auto& window = Game::getInstance().getWindow();
    const auto deltaTimeSeconds = deltaTime.asSeconds();
    const auto ballTop = circle.getPosition().y - circle.getRadius();
    const auto ballBottom = circle.getPosition().y + circle.getRadius();
    
    if (ballTop > window.getSize().y - 0.1f || ballBottom < 0.1f) {
        setAngle(angle + 180);
    }

    circle.move(std::cos(angle) * speed * deltaTimeSeconds, std::sin(angle) * speed * deltaTimeSeconds);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(circle, states);
}

int Ball::getSpeed() {
    return speed;
}

int Ball::getAngle() {
    return angle;
}

const sf::CircleShape& Ball::getCircle() const {
    return circle;
}

void Ball::setSpeed(int newSpeed) {
    speed = newSpeed;
}
 
void Ball::setAngle(int newAngle) {
    angle = newAngle % 360;
}

