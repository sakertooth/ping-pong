#pragma once
#include <SFML/Graphics.hpp>

class State : public sf::Drawable {
public:
    virtual void update(const sf::Time& deltaTime) = 0;
};