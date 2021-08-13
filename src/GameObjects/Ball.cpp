#include "Ball.hpp"
#include "../Game.hpp"
#include <cmath>

Ball::Ball() : speed(500), angle(45) {
    ball.setRadius(5);
    ball.setPosition(5, 5);
    ball.setOrigin(ball.getLocalBounds().width / 2.0f, ball.getLocalBounds().height / 2.0f);
    ball.setFillColor(sf::Color::White);
}

void Ball::init() {}

void Ball::update(const sf::Time& deltaTime) {
    const auto& deltaTimeSeconds = deltaTime.asSeconds();
    ball.move(std::cos(angle) * speed * deltaTimeSeconds, std::sin(angle) * speed * deltaTimeSeconds);

    const auto& window = Game::getInstance().getWindow();
    if (ball.getPosition().y + ball.getRadius() > window.getSize().y ||
        ball.getPosition().y - ball.getRadius() / 2.0f < 0) {
        
        angle += 180;
    }
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

const sf::Vector2f& Ball::getPosition() const {
    return ball.getPosition();
}

void Ball::setSpeed(int newSpeed) {
    speed = newSpeed;
}
 
void Ball::setAngle(int newAngle) {
    if (newAngle < 0) {
        angle = 360 - newAngle;
    }
    else if (newAngle > 360) {
        angle = newAngle - 360;
    }
    else {
        angle = newAngle;
    }
}

