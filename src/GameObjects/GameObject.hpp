#pragma once
#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable {
public:
    virtual void update(const sf::Time& deltaTime) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};