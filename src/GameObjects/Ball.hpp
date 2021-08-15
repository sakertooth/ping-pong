#pragma once
#include "GameObject.hpp"

class Ball : public GameObject {
public:
    Ball();

    int getSpeed();
    int getAngle();
    
    void setSpeed(int newSpeed);
    void setAngle(int newAngle);
    void setPosition(float x, float y);
    const sf::CircleShape& getCircle() const;

    virtual void update(const sf::Time& deltaTime) override;
private:
    int speed;
    int angle;
    sf::CircleShape circle;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};