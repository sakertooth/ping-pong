#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable {
public:
    enum class Axis {
        X,
        Y
    };

    Ball();
    void update(const sf::Time& deltaTime);

    int getSpeed();
    int getAngle();
    
    void setSpeed(const int newSpeed);
    void setAngle(const int newAngle);
    sf::CircleShape& getCircle();

    void reflect(Axis axis, float angleOffset = 0);
private:
    int speed;
    int angle;
    sf::CircleShape circle;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};