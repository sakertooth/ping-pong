#define _USE_MATH_DEFINES

#include "Ball.hpp"
#include "../Game.hpp"
#include <cmath>
#include <iostream>
#include <random>

Ball::Ball() : speed(500), angle(0), acceleration(25), maxSpeed(700) {
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

int Ball::getSpeed() const {
    return speed;
}

int Ball::getAngle() const {
    return angle;
}

int Ball::getRadius() const {
    return circle.getRadius();
}

int Ball::getAcceleration() const {
    return acceleration;
}

int Ball::getMaxSpeed() const {
    return maxSpeed;
}

sf::FloatRect Ball::getGlobalBounds() const {
    return circle.getGlobalBounds();
}

const sf::Vector2f& Ball::getPosition() const {
    return circle.getPosition();
}

void Ball::setSpeed(const int newSpeed) {
    speed = newSpeed;
}
 
void Ball::setAngle(const int newAngle) {
    angle = newAngle % 360;
}

void Ball::setPosition(const float x, const float y) {
    circle.setPosition(x, y);
}

void Ball::reflect(const VectorComponent axis) {
    const auto ballX = std::cos(angle * M_PI/180);
    const auto ballY = std::sin(angle * M_PI/180);
    const int invertX = axis == VectorComponent::X ? -1 : 1;
    const int invertY = axis == VectorComponent::Y ? -1 : 1;

    angle = std::round(std::atan2(invertY * ballY, invertX * ballX) * 180/M_PI);
}