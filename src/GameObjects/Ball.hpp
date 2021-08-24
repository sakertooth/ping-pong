#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable {
public:
    enum class VectorComponent {
        X,
        Y
    };

    Ball();
    void update(const sf::Time& deltaTime);

    int getSpeed() const;
    int getAngle() const;
    float getRadius() const;
    int getAcceleration() const;
    int getMaxSpeed() const;
    sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f& getPosition() const;

    void accelerate();
    void setAngle(const int newAngle);
    void setPosition(const float x, const float y);
    void resetSpeed();
    
    void invert(const VectorComponent vector);
private:
    int speed;
    int angle;
    int acceleration;
    int maxSpeed;
    sf::CircleShape circle;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};