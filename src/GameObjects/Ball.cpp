#include "Ball.hpp"
#include <cmath>

Ball::Ball() : speed(500), angle(315) {
    ball.setRadius(5);
    ball.setFillColor(sf::Color::White);
}

void Ball::init() {}

void Ball::update(const sf::Time& deltaTime) {
    const auto& deltaTimeSeconds = deltaTime.asSeconds();
    ball.move(std::cos(angle) * speed * deltaTimeSeconds, std::sin(angle) * speed * deltaTimeSeconds);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(ball, states);
}

int Ball::getSpeed() {
    return speed;
}

int Ball::getAngle() {
    return angle;
}

void Ball::setSpeed(int newSpeed) {
    speed = newSpeed;
}
 
void Ball::setAngle(int newAngle) {
    angle = newAngle;
}

