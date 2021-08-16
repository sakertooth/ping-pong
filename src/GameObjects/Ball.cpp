#define _USE_MATH_DEFINES

#include "Ball.hpp"
#include "../Game.hpp"
#include <cmath>
#include <iostream>
#include <random>

Ball::Ball() : speed(500), angle(0) {
    circle.setRadius(5);
    circle.setOrigin(circle.getLocalBounds().width / 2.0f, circle.getLocalBounds().height / 2.0f);
    circle.setFillColor(sf::Color::White);
}

void Ball::update(const sf::Time& deltaTime) {
    const auto deltaTimeSeconds = deltaTime.asSeconds();
    circle.move(static_cast<float>(std::cos(angle * M_PI/180)) * speed * deltaTimeSeconds, 
                static_cast<float>(std::sin(angle * M_PI/180)) * speed * deltaTimeSeconds);
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

sf::CircleShape& Ball::getCircle() {
    return circle;
}

void Ball::setSpeed(const int newSpeed) {
    speed = newSpeed;
}
 
void Ball::setAngle(const int newAngle) {
    angle = newAngle % 360;
}

void Ball::reflect(Axis axis, float angleOffset) {
    const auto ballX = std::cos(angle * M_PI/180);
    const auto ballY = std::sin(angle * M_PI/180);

    switch (axis) {
        case Axis::X:
            angle = std::atan2(-ballY, ballX) * 180/M_PI + angleOffset;
            break;
        case Axis::Y:
            angle = std::atan2(ballY, -ballX) * 180/M_PI + angleOffset;
            break;
    }
}