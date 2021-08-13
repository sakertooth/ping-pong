#pragma once
#include "GameObject.hpp"

class Ball : public GameObject {
public:
    Ball();

    int getSpeed();
    int getAngle();
    const sf::Vector2f& getPosition() const;
    
    void setSpeed(int newSpeed);
    void setAngle(int newAngle);

    virtual void update(const sf::Time& deltaTime) override;
    virtual void init() override;
private:
    int speed;
    int angle;
    sf::CircleShape ball;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};