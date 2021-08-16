#pragma once
#include "GameObject.hpp"

class Ball : public GameObject {
public:

    enum class Axis {
        X,
        Y
    };

    Ball();

    int getSpeed();
    int getAngle();
    
    void setSpeed(const int newSpeed);
    void setAngle(const int newAngle);
    sf::CircleShape& getCircle();

    void reflect(Axis axis, float angleOffset = 0);

    virtual void update(const sf::Time& deltaTime) override;
private:
    int speed;
    int angle;
    sf::CircleShape circle;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};