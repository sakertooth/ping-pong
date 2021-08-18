#pragma once
#include "../Updatable.hpp"
#include "Ball.hpp"

class Paddle : public Updatable {
public:
    enum class PaddleOrientation {
        LEFT,
        RIGHT,
        DOWN
    };

    Paddle();
    Paddle(const sf::Vector2f& position, const sf::Vector2f& size, PaddleOrientation orientation, Ball* activeBall);

    void update(const sf::Time& deltaTime) override;

    int getSpeed() const;
    const sf::Vector2f& getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;
    PaddleOrientation getOrientation() const;
    std::pair<sf::FloatRect, sf::FloatRect> getIntersectionRects() const;

    void setPosition(const float x, const float y);

    void moveUp(const sf::Time& deltaTime);
    void moveDown(const sf::Time& deltaTime);
    void moveLeft(const sf::Time& deltaTime);
    void moveRight(const sf::Time& deltaTime);

private:
    int speed;
    sf::RectangleShape rect;
    Ball* activeBall;
    PaddleOrientation orientation;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};