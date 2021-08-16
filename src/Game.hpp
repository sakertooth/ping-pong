#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include "Updatable.hpp"

class Game 
{
public:
    Game();
    ~Game();
    
    void handleEvent();
    void update(const sf::Time& deltaTime);
    void draw();
    void stop();

    void pushState(std::unique_ptr<Updatable> state);
    void popState();

    const bool isRunning();

    static Game& getInstance();
    const sf::RenderWindow& getWindow();
    const sf::Font& getFont();

private:
    sf::RenderWindow window;
    sf::Font font;
    std::stack<std::unique_ptr<Updatable>> states;    
};
