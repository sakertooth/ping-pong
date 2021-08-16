#pragma once
#include "GameObject.hpp"
#include "Ball.hpp"

class Paddle : public GameObject {
public:
    enum class PaddleOrientation {
        LEFT,
        RIGHT,
        DOWN
    };

    Paddle();
    virtual void init(const sf::Vector2f& position, const sf::Vector2f& size, PaddleOrientation orientation, Ball* activeBall);
    virtual void update(const sf::Time& deltaTime) override;

    int getSpeed();
    sf::RectangleShape& getRect();
    PaddleOrientation getOrientation();

    void moveUp(const sf::Time& deltaTime);
    void moveDown(const sf::Time& deltaTime);
    void moveLeft(const sf::Time& deltaTime);
    void moveRight(const sf::Time& deltaTime);

private:
    int speed;
    sf::RectangleShape rect;
    Ball* activeBall;
    PaddleOrientation orientation;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};