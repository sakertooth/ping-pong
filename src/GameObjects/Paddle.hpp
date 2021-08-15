#pragma once
#include "GameObject.hpp"
#include "Ball.hpp"

class Paddle : public GameObject {
public:
    enum class PaddleOrientation {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    Paddle();
    virtual void init(const sf::Vector2f& position, PaddleOrientation orientation, Ball* activeBall);
    virtual void update(const sf::Time& deltaTime) override;

    const sf::RectangleShape& getRect() const;
    void moveDown(const sf::Time& deltaTime);
    void moveUp(const sf::Time& deltaTime);

private:
    int speed;
    sf::RectangleShape rect;
    Ball* activeBall;
    PaddleOrientation orientation;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};