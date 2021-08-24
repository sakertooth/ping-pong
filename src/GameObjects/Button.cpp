#include "Button.hpp"
#include "../Game.hpp"
#include <iostream>
#include <cmath>

Button::Button() {
    setRectColor(sf::Color::Black);
    setHoverColor(sf::Color::White);
    text.setFont(Game::getInstance().getFont());
    text.setCharacterSize(32);
}

void Button::update(const sf::Time&) {
    auto mousePos = sf::Mouse::getPosition(Game::getInstance().getWindow());
    if (rect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        rect.setFillColor(hoverColor);
        text.setFillColor(rectColor);

        bool clicked = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
        if (!isMouseDown && clicked) {
            isMouseDown = true;
            if (onClickFn) {
                onClickFn();
            }
        }
        else if (!clicked) {
            isMouseDown = false;
        }
    }
    else {
        rect.setFillColor(rectColor);
        text.setFillColor(hoverColor);
    }
    
}

void Button::onClick(const std::function<void()>& fn) {
    onClickFn = fn;
}

void Button::setPosition(float x, float y) {   
    rect.setOrigin(std::round(rect.getLocalBounds().width / 2.0f), std::round(rect.getLocalBounds().height / 2.0f));
    rect.setPosition(x, y);

    text.setOrigin(std::round(text.getLocalBounds().width / 2.0f), std::round(rect.getLocalBounds().height / 2.0f));
    text.setPosition(x, y);
}

void Button::setText(const std::string& str) {
    text.setString(str);

    float rectWidth = text.getLocalBounds().width + 15;
    float rectHeight = text.getLocalBounds().height + 15;
    rect.setSize(sf::Vector2f{rectWidth, rectHeight});
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
    target.draw(text, states);
}

void Button::setRectColor(const sf::Color& color) {
    rectColor = color;
}

void Button::setHoverColor(const sf::Color& color) {
    hoverColor = color;
}
