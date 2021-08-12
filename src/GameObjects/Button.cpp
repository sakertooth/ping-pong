#include "Button.hpp"
#include "../Game.hpp"
#include <iostream>

void Button::update(const sf::Time& deltaTime) {
    const auto& mousePos = sf::Mouse::getPosition(Game::getInstance().getWindow());
    std::cout << mousePos.x << ":" << mousePos.y << '\n';
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
    target.draw(text, states);
}

sf::RectangleShape& Button::getRect() {
    return rect;
}

sf::Text& Button::getText() {
    return text;
}
