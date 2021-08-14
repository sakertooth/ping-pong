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
    const auto& window = Game::getInstance().getWindow();
    const auto& ballTop = std::round(ball.getPosition().y - ball.getRadius());
    const auto& ballBottom = std::round(ball.getPosition().y + ball.getRadius());

    if (ballTop > window.getSize().y || ballBottom < 0) {
        angle = 180;
    }

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

const sf::Vector2f& Ball::getPosition() const {
    return ball.getPosition();
}

void Ball::setSpeed(int newSpeed) {
    speed = newSpeed;
}
 
void Ball::setAngle(int newAngle) {
    angle = newAngle;
}

