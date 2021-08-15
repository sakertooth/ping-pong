#define _USE_MATH_DEFINES

#include "Ball.hpp"
#include "../Game.hpp"
#include <cmath>
#include <iostream>
#include <random>


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

    if (ballTop < 1.0f || ballBottom > static_cast<float>(window.getSize().y) - 1.0f) {
        angle = -angle;
        // set the position to prevent it from being stuck
    }

    circle.move(std::cos(angle * M_PI/180) * speed * deltaTimeSeconds, std::sin(angle * M_PI/180) * speed * deltaTimeSeconds);
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

