#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Paddle : public sf::Drawable {
public:
    enum class PaddleOrientation {
        LEFT,
        RIGHT,
        DOWN
    };

    Paddle();
    Paddle(const sf::Vector2f& position, PaddleOrientation orientation);

    int getSpeed() const;
    const sf::Vector2f& getPosition() const;
    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;
    PaddleOrientation getOrientation() const;

    void setPosition(const float x, const float y);

    void moveUp(const sf::Time& deltaTime);
    void moveDown(const sf::Time& deltaTime);
    void moveLeft(const sf::Time& deltaTime);
    void moveRight(const sf::Time& deltaTime);

private:
    int speed;
    sf::RectangleShape rect;
    PaddleOrientation orientation;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};