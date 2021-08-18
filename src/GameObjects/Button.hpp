#pragma once
#include "../Updatable.hpp"
#include <SFML/Graphics.hpp>
#include <functional>

class Button : public Updatable {
public:
    Button();
    
    void update(const sf::Time& deltaTime) override;
    void onClick(const std::function<void()>& fn);

    void setPosition(float x, float y);
    void setText(const std::string& str);

    void setRectColor(const sf::Color& color);
    void setHoverColor(const sf::Color& color);

private:
    sf::RectangleShape rect;
    sf::Text text;
    
    sf::Color rectColor;
    sf::Color hoverColor;

    bool isMouseDown;
    std::function<void()> onClickFn;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};