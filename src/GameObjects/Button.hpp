#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Button : public GameObject {
public:
    virtual void update(const sf::Time& deltaTime) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::RectangleShape& getRect();
    sf::Text& getText();
private:
    sf::RectangleShape rect;
    sf::Text text;
    
    sf::Color rectColor;
    sf::Color hoverColor;
};